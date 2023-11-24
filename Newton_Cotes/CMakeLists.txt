cmake_minimum_required(VERSION 3.25)
project(Newton_Cotes)

set(CMAKE_CXX_STANDARD 17)

add_executable(Newton_Cotes
        Newton_Cotes.cpp
        Newton_Cotes.h
        Split.cpp
        Split.h)
