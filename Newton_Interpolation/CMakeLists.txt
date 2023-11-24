cmake_minimum_required(VERSION 3.25)
project(Newton)

set(CMAKE_CXX_STANDARD 17)

include_directories("D:/eigen3/eigen-3.4.0")

add_executable(Newton Newton.cpp Newton.h)

