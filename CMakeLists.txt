cmake_minimum_required(VERSION 4.1)
project(Is_that_a_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Is_that_a_tree
        main.cpp
        Graph.cpp
        Graph.h
        Vertex.cpp
        Vertex.h)
