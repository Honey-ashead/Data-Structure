cmake_minimum_required(VERSION 3.22)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList main.cpp
        List.cpp
        List.h)
#include_directories(E:\\boost\\build\\include\\boost-1_76)
#link_libraries(E:\\boost\\build\\lib)
