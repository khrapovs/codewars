cmake_minimum_required(VERSION 3.24)

project(codewars)

set(CMAKE_CXX_STANDARD 17)

set(IGLOO_PATH igloo)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src)

include_directories(${SOURCE_PATH})
include_directories(${IGLOO_PATH})

file(GLOB TEST_FILES CONFIGURE_DEPENDS tests/*.cpp src/**/*.cpp)

add_executable(even-or-odd scripts/even_or_odd.cpp src/004_even_or_odd/even_or_odd.cpp)

add_executable(codewars-test ${TEST_FILES})
