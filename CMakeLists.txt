project(TEST_MULTITHREAD_CAFFE2)
cmake_minimum_required(VERSION 3.2)

add_definitions(-std=c++11)
set(SRC main.cpp)
set(${CMAKE_VERBOSE_MAKEFILE} ON)
#set(SRC print_registered_core_operators.cc)

# caffe2
if (${CMAKE_BUILD_TYPE} STREQUAL "Release" )
    list(APPEND CMAKE_PREFIX_PATH "/opt/Caffe2")
    message(STATUS "caffe2 in /opt/caffe2")
else()
    list(APPEND CMAKE_PREFIX_PATH "/opt/Caffe2-Debug")
    message(STATUS "caffe2 in /opt/caffe2-debug")
endif()

find_package(Caffe2)
if (Caffe2_FOUND)
    message(STATUS "find Caffe2")
    message(STATUS "caffe2 inc " ${Caffe2_INCLUDE_DIRS})
    message(STATUS "caffe2 lib " ${Caffe2_MAIN_LIBS})
else()
    message(STATUS "cannot find caffe2")
endif()

set(OPENCV_LIBS "")
find_package(OpenCV 3 QUIET COMPONENTS core highgui imgproc imgcodecs)
if(OpenCV_FOUND)
    message(STATUS "OpenCV3 Found (${OpenCV_CONFIG_PATH})")
    list(APPEND OPENCV_LIBS ${OpenCV_LIBS})
endif()
if(NOT OpenCV_FOUND)
    # OpenCV 2
    find_package(OpenCV QUIET COMPONENTS core highgui imgproc)
    message(STATUS "OpenCV2 Found (${OpenCV_CONFIG_PATH})")
    list(APPEND OPENCV_LIBS ${OpenCV_LIBS})
endif()
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    message(STATUS "OpenCV libs: (${OPENCV_LIBS})")
else()
    message(WARNING "Not find OpenCV. project maybe invalid ")
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/third_party)
include_directories(/opt/intel/mkl/include)

add_definitions(-DUSE_GPU)
add_definitions(-DLOG_OUT)
add_definitions(-DIMG_PATH="${CMAKE_SOURCE_DIR}/")
add_executable(test_multi_thread_caffe2 ${SRC})


target_link_libraries(test_multi_thread_caffe2 -Wl,--no-as-needed caffe2 caffe2_gpu)
target_link_libraries(test_multi_thread_caffe2 ${OPENCV_LIBS} protobuf)

message(STATUS "cmake build type:" ${CMAKE_BUILD_TYPE})
