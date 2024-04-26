cmake_minimum_required(VERSION 3.27)
project(DSA_Assignment)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA_Assignment main.cpp
        Stack/Stack.cpp
        ArrayBasedStack/ArrayBasedStack.cpp
        SingleLinkedList/SingleLinkedLIst.h
        SingleLinkedList/SingleLinkedLIst.cpp
        "circular linked List/circular_linked_list.h"
        "circular linked List/circular_linked_list.cpp")
