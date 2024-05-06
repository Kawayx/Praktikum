cmake_minimum_required(VERSION 3.28)
project(ADS_Praktika)

set(CMAKE_CXX_STANDARD 26)

add_executable(ADS_Praktika main.cpp
        Ring.h
        RingNode.h
        Ring.cpp
        RingNode.cpp
        RingTest.cpp
        catch.h)
