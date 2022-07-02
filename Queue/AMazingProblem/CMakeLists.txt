cmake_minimum_required(VERSION 3.22)
project(AMazingProblem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AMazingProblem
        definition.h
        stack_solution.cpp)
