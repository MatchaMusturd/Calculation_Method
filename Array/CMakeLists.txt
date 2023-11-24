cmake_minimum_required(VERSION 3.25)
project(ARRAY)

set(CMAKE_CXX_STANDARD 17)

include_directories("D:/eigen3/eigen-3.4.0")
add_executable(ARRAY Array1.cpp Array1.h arrayy.cpp main.cpp leastsquares.cpp dooli.cpp esti.cpp ite.cpp fit.cpp matrix.cpp rev_1.cpp l_f.cpp arrayy.h leatsquares.h matrix_.h)
