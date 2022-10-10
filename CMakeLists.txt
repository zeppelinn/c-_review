cmake_minimum_required(VERSION 3.21)
project(imooc_demo)

set(CMAKE_CXX_STANDARD 14)

#   QT配置
set(CMAKE_PREFIX_PATH /Users/lijun/Environment/QT/env_5_9_4/5.9.4/clang_64/lib/cmake)
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#   FFmpeg配置
link_directories(./lib/)
include_directories(./include/)

add_executable(imooc_demo main.cpp demo/demo_1.cpp demo/demo_2.cpp demo/demo_3.cpp demo/demo_4_container.cpp demo/demo_5_string.cpp demo/demo_6_pointer.cpp demo/demo_7_memory_block.cpp demo/demo_8_type.cpp demo/demo_9/demo_9_function.cpp demo/demo_9/demo_9_function.h demo/demo_9/demo_9.cpp demo/demo_10/Complex.cpp demo/demo_10/Complex.h demo/demo_10/demo_10_oop.cpp demo/demo_11_stl/demo_container.cpp demo/demo_11_stl/demo_functor.cpp demo/demo_11_stl/demo_algorithm.cpp demo/demo_11_stl/demo_iterator.cpp demo/demo_11_stl/demo_adapter.cpp demo/demo_11_stl/demo_multi_thread.cpp demo/demo_12_makefile/demo_12_makefile.cpp demo/demo_ffmpeg.cpp)

target_link_libraries(
        imooc_demo
        avcodec
        avdevice
        avfilter
        avformat
        Qt5::Widgets
)