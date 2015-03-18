cmake_minimum_required(VERSION 3.0)

project(opencv-bing-test)

add_definitions(-DCPU_ONLY)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-W -Wall -O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++11 -stdlib=libc++")
set(CMAKE_CXX_FLAGS_RELEASE "-W -Wall -O3 -std=c++11 -stdlib=libc++")

set(OPENCV_ROOT "$ENV{HOME}/dev-pack/opencv/local")

include_directories(${PROJECT_SOURCE_DIR} /usr/include /usr/local/include ${OPENCV_ROOT}/include)
link_directories(/usr/lib /usr/local/lib ${OPENCV_ROOT}/lib)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(opencv_bing_test ${SRCS})
target_link_libraries(opencv_bing_test glog opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs opencv_saliency)
