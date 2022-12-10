cmake_minimum_required(VERSION 3.24)
project(codewars)

set(CMAKE_CXX_STANDARD 17)

set(IGLOO_PATH ${CMAKE_SOURCE_DIR}/external/igloo)

include_directories(square_n_sum src/square_n_sum)
include_directories(igloo ${IGLOO_PATH})

add_executable(codewars
        src/square_n_sum/square_n_sum.cpp
        src/square_n_sum/square_n_sum.h)

add_executable(codewars-test
        tests/main.cpp
        tests/test_square_n_sum.cpp)