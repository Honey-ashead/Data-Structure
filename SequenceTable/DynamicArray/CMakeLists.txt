cmake_minimum_required(VERSION 3.21)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DynamicArray
        LinearList.cpp
        LinearList.h
        main.cpp
        )
