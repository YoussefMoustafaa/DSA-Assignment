cmake_minimum_required(VERSION 3.27)
project(DSA_Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_Assignment main.cpp
        Stack/Stack.cpp
        ArrayBasedStack/ArrayBasedStack.cpp
        SingleLinkedLIst.h
        SingleLinkedLIst.cpp)
