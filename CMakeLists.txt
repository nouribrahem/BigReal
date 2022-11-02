cmake_minimum_required(VERSION 3.21)
project(BigReal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigReal
        BigReal.cpp
        BigReal.h
        BigDecimalIntClass.cpp
        BigDecimalIntClass.h
        main.cpp)
