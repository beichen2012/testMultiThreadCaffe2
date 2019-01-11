#include "BTimer.hpp"
#include "spdhelper.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <caffe2/core/common.h>
#include <caffe2/core/workspace.h>
#include <caffe2/utils/proto_utils.h>
#include <caffe2/core/init.h>
#include <caffe2/core/operator.h>


std::string init_path = std::string(IMG_PATH) + R"(pnet_20181010_init_net_final.pb)";
std::string predict_path = std::string(IMG_PATH) + R"(pnet_20181010_predict_net.pb)";

cv::Mat gsrc;

int Preprocess(const cv::Mat& src, caffe2::TensorCPU& input)
{
    //to float
    cv::Mat img;
    src.convertTo(img, CV_32F);

    // warp input
    int N = 1;
    int C = img.channels();
    int H = img.rows;
    int W = img.cols;
    input.Resize(std::vector<int>{N,C,H,W});
    float* data = input.mutable_data<float>();
    std::vector<cv::Mat> bgr;
    for(int i = 0; i < C; i++)
    {
        cv::Mat channel(H, W, CV_32FC1, data);
        data += H * W;
        bgr.push_back(channel);
    }
    //
    cv::split(img, bgr);
    return 0;
}


int Preprocess(const std::vector<cv::Mat>& src, caffe2::TensorCPU& input)
{
    if(src.size() <= 0)
        return -1;
    //warp input
    int N = src.size();
    int C = src[0].channels();
    int H = src[0].rows;
    int W = src[0].cols;

    std::vector<cv::Mat> imgs;
    imgs.resize(N);

    //mean and scale
    for(int i = 0; i < N; i++)
    {
        src[i].convertTo(imgs[i], CV_32F);
    }

    //
    input.Resize(std::vector<int>{N,C,H,W});
    float* data = input.mutable_data<float>();
    for(int n = 0; n < N; n++)
    {
        std::vector<cv::Mat> bgr;
        for(int c = 0; c < C; c++)
        {
            cv::Mat channel(H, W, CV_32FC1, data);
            data += H * W;
            bgr.push_back(channel);
        }
        cv::split(imgs[n], bgr);
    }


    return 0;
}

int FeedInputBlob(caffe2::Blob* data_blob, caffe2::TensorCPU& input, caffe2::DeviceType device_type_)
{
    if(device_type_ == caffe2::CPU)
    {
        caffe2::BlobGetMutableTensor(data_blob, device_type_)->ResizeLike(input);
        caffe2::BlobGetMutableTensor(data_blob, device_type_)->ShareData(input);
        //data_blob->GetMutableTensor(device_type_)->ResizeLike(input);
        //data_blob->GetMutableTensor(device_type_)->ShareData(input);
    }
    else if(device_type_ == caffe2::CUDA)
    {
        caffe2::BlobGetMutableTensor(data_blob, device_type_)->CopyFrom(input);
        //data_blob->GetMutableTensor(device_type_)->CopyFrom(input);
    }
    else
    {
        return -1;
    }
    return 0;
}



int testSingleThread(caffe2::DeviceType device, int device_id = 0)
{
    ENTER_FUNC;

    BTimer timer;
    auto w = std::shared_ptr<caffe2::Workspace>(new caffe2::Workspace("root"));
    //device option
    caffe2::DeviceOption device_option;
    device_option.set_device_type((int)device);
    device_option.set_device_id(0);


    caffe2::NetDef initNet;
    CAFFE_ENFORCE(caffe2::ReadProtoFromFile(init_path, &initNet));

    //clear net preset device option
    for(int i = 0; i < initNet.op_size(); i++)
    {
        auto p = initNet.mutable_op(i);
        auto type = p->type();
        //std::cout << i << type << "\t";
        //std::cout << "device op:" << p->device_option().device_type() << std::endl;
        //p->clear_device_option();
        p->release_device_option();
    }

    initNet.mutable_device_option()->CopyFrom(device_option);
    initNet.set_num_workers(1);
    w->RunNetOnce(initNet);

    caffe2::NetDef predictNet;
    CAFFE_ENFORCE(caffe2::ReadProtoFromFile(predict_path, &predictNet));

    for(int i = 0; i < predictNet.op_size(); i++)
    {
        auto p = predictNet.mutable_op(i);
        //p->set_domain("c10");
        auto type = p->type();
        p->release_device_option();   //maybe this line is right
    }

    //device option
    predictNet.mutable_device_option()->CopyFrom(device_option);
    predictNet.set_num_workers(1);
    w->CreateNet(predictNet);
    auto net_name_ = predictNet.name();

    cv::Mat src = gsrc.clone();
    std::vector<cv::Mat> vsrc;
    if (device == caffe2::CUDA)
    {
        for(int i = 0; i <1; i++)
            vsrc.push_back(src);

        caffe2::TensorCPU input(caffe2::CPU);
        Preprocess(vsrc, input);
        auto blob_in = w->GetBlob(std::string("data"));
        FeedInputBlob(blob_in, input, device);

        auto* net = w->GetNet(net_name_);

        net->TEST_Benchmark(5, 100, true);

//        for(;;)
//        {
//            timer.reset();
//            p->pw_->RunNet(p->net_name_);
//            LOGI("runnet time cost: {} ms", timer.elapsed());
//        }
    } else{
        caffe2::TensorCPU input(caffe2::CPU);
        Preprocess(src, input);
        auto blob_in = w->GetBlob(std::string("data"));
        FeedInputBlob(blob_in, input, device);

        auto* net = w->GetNet(net_name_);

        net->TEST_Benchmark(5, 100, true);
//        for(;;)
//        {
//            timer.reset();
//            p->pw_->RunNet(p->net_name_);
//            LOGI("runnet time cost: {} ms", timer.elapsed());
//        }
    }


    LEAVE_FUNC;
    return 0;
}

void testMultiThread(int thread_num, int device_type)
{
    ENTER_FUNC;
    caffe2::DeviceType device = caffe2::CUDA;
    if (device_type == 0)
        device = caffe2::CPU;
    std::vector<std::thread> vt;
    for(int i = 0; i < thread_num; i++)
    {
        vt.emplace_back(std::thread(testSingleThread, device, i));
    }
    for(auto& i : vt)
        i.join();

    LEAVE_FUNC;
}


#include "cmdline.h"
int main(int argc, char* argv[])
{
    cmdline::parser a ;
    a.add<int>("num_threads", 't', "num threads", false, 1);
    a.add<int>("device_type", 'd', "device type, 0 for CPU, 1 for GPU", false, 0);

    a.parse_check(argc, argv);
    int num_thread = a.get<int>("num_threads");
    int device_type = a.get<int>("device_type");
    LOGI("num threads: {}, device type is: {}", num_thread, device_type);

    ENTER_FUNC;
    caffe2::GlobalInit();
    gsrc = cv::imread(std::string(IMG_PATH) + "faces1.jpg");
    if (!gsrc.data) {
        LOGE("error load image!");
        LEAVE_FUNC;
        return 0;
    }

    testMultiThread(num_thread, device_type);

    LEAVE_FUNC;
    return 0;
}
