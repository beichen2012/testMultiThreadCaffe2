### CPU, 一个线程
```
# beichen2012 @ beichen2012 in ~/projects/testMultiThreadCaffe2/build [9:39:29]
$ ./test_multi_thread_caffe2 -t 1 -d 0
[2018-12-26 09:39:31.571517] [t:30205] [info] num threads: 1, device type is: 0
[2018-12-26 09:39:31.571559] [t:30205] [debug] enter function: main
[2018-12-26 09:39:31.583259] [t:30205] [debug] enter function: testMultiThread
[2018-12-26 09:39:31.587204] [t:30210] [debug] enter function: testSingleThread
Starting benchmark.
Running warmup runs.
Main runs.
Main run finished. Milliseconds per iter: 262.414. Iters per second: 3.81077
Operator #0 (conv1, Conv) 64.2127 ms/iter (0.403112 GFLOP, 6.277765 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 4.30467 ms/iter
Operator #2 (pool1, MaxPool) 12.6298 ms/iter
Operator #3 (conv2, Conv) 52.6905 ms/iter (0.532466 GFLOP, 10.105538 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 1.57282 ms/iter
Operator #5 (conv3, Conv) 87.5214 ms/iter (1.687910 GFLOP, 19.285678 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 3.35488 ms/iter
Operator #7 (conv4-1, Conv) 3.07092 ms/iter (0.023443 GFLOP, 7.633921 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 3.53387 ms/iter (0.046886 GFLOP, 13.267712 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 13.2794 ms/iter (0.117216 GFLOP, 8.826882 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 1.63824 ms/iter
Time per operator type:
        224.309 ms.    90.5167%. Conv
        12.6298 ms.    5.09658%. MaxPool
        9.23237 ms.     3.7256%. PRelu
        1.63824 ms.   0.661087%. Softmax
        247.809 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
        0.02732 MB in Total
[2018-12-26 09:40:24.068545] [t:30210] [debug] leave function: testSingleThread
[2018-12-26 09:40:24.080819] [t:30205] [debug] leave function: testMultiThread
[2018-12-26 09:40:24.080849] [t:30205] [debug] leave function: main
```
# CPU 两个线程
```
# beichen2012 @ beichen2012 in ~/projects/testMultiThreadCaffe2/build [9:40:24]
$ ./test_multi_thread_caffe2 -t 2 -d 0
[2018-12-26 09:40:38.053500] [t:30635] [info] num threads: 2, device type is: 0
[2018-12-26 09:40:38.053544] [t:30635] [debug] enter function: main
[2018-12-26 09:40:38.065358] [t:30635] [debug] enter function: testMultiThread
[2018-12-26 09:40:38.067250] [t:30640] [debug] enter function: testSingleThread
[2018-12-26 09:40:38.071629] [t:30641] [debug] enter function: testSingleThread
Starting benchmark.
Running warmup runs.
Starting benchmark.
Running warmup runs.
Main runs.
Main runs.
Main run finished. Milliseconds per iter: 459.67. Iters per second: 2.17547
Main run finished. Milliseconds per iter: 459.956. Iters per second: 2.17412
Operator #0 (conv1, Conv) 119.669 ms/iter (0.403112 GFLOP, 3.368549 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 9.07301 ms/iter
Operator #2 (pool1, MaxPool) 16.7446 ms/iter
Operator #3 (conv2, Conv) 101.072 ms/iter (0.532466 GFLOP, 5.268164 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 3.63563 ms/iter
Operator #5 (conv3, Conv) 158.866 ms/iter (1.687910 GFLOP, 10.624764 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 7.58746 ms/iter
Operator #7 (conv4-1, Conv) 7.78595 ms/iter (0.023443 GFLOP, 3.010963 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 8.56217 ms/iter (0.046886 GFLOP, 5.475995 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 24.3039 ms/iter (0.117216 GFLOP, 4.822922 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 2.59232 ms/iter
Time per operator type:
         420.26 ms.    91.3821%. Conv
        20.2961 ms.    4.41323%. PRelu
        16.7446 ms.    3.64099%. MaxPool
        2.59232 ms.    0.56368%. Softmax
        459.893 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
        0.02732 MB in Total
[2018-12-26 09:42:12.511365] [t:30640] [debug] leave function: testSingleThread
Operator #0 (conv1, Conv) 119.408 ms/iter (0.403112 GFLOP, 3.375921 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 9.25622 ms/iter
Operator #2 (pool1, MaxPool) 17.079 ms/iter
Operator #3 (conv2, Conv) 103.913 ms/iter (0.532466 GFLOP, 5.124156 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 3.69071 ms/iter
Operator #5 (conv3, Conv) 156.734 ms/iter (1.687910 GFLOP, 10.769302 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 7.30084 ms/iter
Operator #7 (conv4-1, Conv) 7.33148 ms/iter (0.023443 GFLOP, 3.197610 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 8.24795 ms/iter (0.046886 GFLOP, 5.684611 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 23.8816 ms/iter (0.117216 GFLOP, 4.908207 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 2.7016 ms/iter
Time per operator type:
        419.515 ms.    91.2895%. Conv
        20.2478 ms.    4.40606%. PRelu
         17.079 ms.    3.71652%. MaxPool
         2.7016 ms.   0.587888%. Softmax
        459.544 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
        0.02732 MB in Total
[2018-12-26 09:42:12.532254] [t:30641] [debug] leave function: testSingleThread
[2018-12-26 09:42:12.545221] [t:30635] [debug] leave function: testMultiThread
[2018-12-26 09:42:12.545244] [t:30635] [debug] leave function: main
```
# GPU, 1个线程
```
# beichen2012 @ beichen2012 in ~/projects/testMultiThreadCaffe2/build [9:42:12]
$ ./test_multi_thread_caffe2 -t 1 -d 1
[2018-12-26 09:43:33.492597] [t:31477] [info] num threads: 1, device type is: 1
[2018-12-26 09:43:33.492640] [t:31477] [debug] enter function: main
[2018-12-26 09:43:34.846994] [t:31477] [debug] enter function: testMultiThread
[2018-12-26 09:43:34.847175] [t:31491] [debug] enter function: testSingleThread
Starting benchmark.
Running warmup runs.
Main runs.
Main run finished. Milliseconds per iter: 6.14302. Iters per second: 162.786
Operator #0 (conv1, Conv) 1.21185 ms/iter (0.403112 GFLOP, 332.641025 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 0.377263 ms/iter
Operator #2 (pool1, MaxPool) 0.351758 ms/iter
Operator #3 (conv2, Conv) 0.597991 ms/iter (0.532466 GFLOP, 890.424370 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 0.151417 ms/iter
Operator #5 (conv3, Conv) 0.926509 ms/iter (1.687910 GFLOP, 1821.795975 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 0.297126 ms/iter
Operator #7 (conv4-1, Conv) 0.268785 ms/iter (0.023443 GFLOP, 87.219209 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 0.292833 ms/iter (0.046886 GFLOP, 160.112850 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 0.365797 ms/iter (0.117216 GFLOP, 320.440356 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 1.17712 ms/iter
Time per operator type:
        3.66377 ms.    60.8756%. Conv
        1.17712 ms.    19.5585%. Softmax
       0.825806 ms.    13.7212%. PRelu
       0.351758 ms.    5.84466%. MaxPool
        6.01845 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
        0.02732 MB in Total
[2018-12-26 09:43:36.539269] [t:31491] [debug] leave function: testSingleThread
[2018-12-26 09:43:36.543485] [t:31477] [debug] leave function: testMultiThread
[2018-12-26 09:43:36.543520] [t:31477] [debug] leave function: main
```
# GPU 两个线程
```
# beichen2012 @ beichen2012 in ~/projects/testMultiThreadCaffe2/build [9:43:36]
$ ./test_multi_thread_caffe2 -t 2 -d 1
[2018-12-26 09:43:41.458985] [t:31512] [info] num threads: 2, device type is: 1
[2018-12-26 09:43:41.459030] [t:31512] [debug] enter function: main
[2018-12-26 09:43:42.805008] [t:31512] [debug] enter function: testMultiThread
[2018-12-26 09:43:42.805170] [t:31526] [debug] enter function: testSingleThread
[2018-12-26 09:43:42.805213] [t:31527] [debug] enter function: testSingleThread
Starting benchmark.
Running warmup runs.
Starting benchmark.
Running warmup runs.
Main runs.
Main runs.
Main run finished. Milliseconds per iter: 10.6799. Iters per second: 93.6341
Main run finished. Milliseconds per iter: 10.6793. Iters per second: 93.6387
Operator #0 (conv1, Conv) 1.29747 ms/iter (0.403112 GFLOP, 310.689884 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 1.13982 ms/iter
Operator #2 (pool1, MaxPool) 0.721617 ms/iter
Operator #3 (conv2, Conv) 1.27938 ms/iter (0.532466 GFLOP, 416.189389 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 0.559791 ms/iter
Operator #5 (conv3, Conv) 1.21708 ms/iter (1.687910 GFLOP, 1386.848205 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 0.891821 ms/iter
Operator #7 (conv4-1, Conv) 0.837963 ms/iter (0.023443 GFLOP, 27.976423 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 0.399469 ms/iter (0.046886 GFLOP, 117.371790 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 0.609606 ms/iter (0.117216 GFLOP, 192.281614 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 1.65649 ms/iter
Time per operator type:
        5.64098 ms.     53.164%. Conv
        2.59143 ms.    24.4232%. PRelu
        1.65649 ms.    15.6118%. Softmax
       0.721617 ms.    6.80096%. MaxPool
        10.6105 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
Operator #0 (0.02732conv1, Conv)  MB in Total
2.6726 ms/iter (0.403112 GFLOP, 150.831368 GFLOPS) (29.860160 MB) (0.001080 MB)
Operator #1 (conv1, PRelu) 0.646715 ms/iter
Operator #2 (pool1, MaxPool) 0.76157 ms/iter
Operator #3 (conv2, Conv) 0.867504 ms/iter (0.532466 GFLOP, 613.790869 GFLOPS) (11.832576 MB) (0.005760 MB)
Operator #4 (conv2, PRelu) 0.72452 ms/iter
Operator #5 (conv3, Conv) 1.54447 ms/iter (1.687910 GFLOP, 1092.874254 GFLOPS) (23.443200 MB) (0.018432 MB)
Operator #6 (conv3, PRelu) 0.518491 ms/iter
Operator #7 (conv4-1, Conv) 0.464047 ms/iter (0.023443 GFLOP, 50.519024 GFLOPS) (1.465200 MB) (0.000256 MB)
Operator #8 (conv4-2, Conv) 0.587637 ms/iter (0.046886 GFLOP, 79.788071 GFLOPS) (2.930400 MB) (0.000512 MB)
Operator #9 (conv4-3, Conv) 0.477141 ms/iter (0.117216 GFLOP, 245.662997 GFLOPS) (7.326000 MB) (0.001280 MB)
Operator #10 (prob1, Softmax) 1.34668 ms/iter
Time per operator type:
         6.6134 ms.    62.3237%. Conv
        1.88973 ms.    17.8085%. PRelu
        1.34668 ms.    12.6909%. Softmax
        0.76157 ms.    7.17692%. MaxPool
        10.6114 ms in Total
FLOP per operator type:
        2.81103 GFLOP.        100%. Conv
        2.81103 GFLOP in Total
Feature Memory Read per operator type:
        98.6548 MB.        100%. Conv
        98.6548 MB in Total
Feature Memory Written per operator type:
        76.8575 MB.        100%. Conv
        76.8575 MB in Total
Parameter Memory per operator type:
        0.02732 MB.        100%. Conv
        0.02732 MB in Total
[2018-12-26 09:43:45.435653] [t:31527] [debug] leave function: testSingleThread
[2018-12-26 09:43:45.436720] [t:31526] [debug] leave function: testSingleThread
[2018-12-26 09:43:45.446848] [t:31512] [debug] leave function: testMultiThread
[2018-12-26 09:43:45.446872] [t:31512] [debug] leave function: main
```
