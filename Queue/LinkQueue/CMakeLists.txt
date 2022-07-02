cmake_minimum_required(VERSION 3.22)
project(LinkQueue)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinkQueue
        LinkQueue.cpp
        LinkQueue.h
        main.cpp)
