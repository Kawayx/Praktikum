cmake_minimum_required(VERSION 3.28)
project(1_2)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ExportZielanalyse.csv ${CMAKE_CURRENT_BINARY_DIR}/ExportZielanalyse.csv COPYONLY)


set(CMAKE_CXX_STANDARD 26)

add_executable(1_2
        catch.h
        main.cpp
        Tree.cpp
        TreeNode.cpp
        TreeTest.cpp
)
