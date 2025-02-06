cmake_minimum_required(VERSION 3.30)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithms main.cpp
        src/data-structures/StaticArray.cpp
        src/data-structures/StaticArray.h
        src/data-structures/DynamicArray.cpp
        src/data-structures/DynamicArray.h)
