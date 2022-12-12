cmake_minimum_required(VERSION 3.24)
project(codewars)

set(CMAKE_CXX_STANDARD 17)

set(IGLOO_PATH ${CMAKE_SOURCE_DIR}/external/igloo)

set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src)

include_directories(${SOURCE_PATH}/multiply)
include_directories(${SOURCE_PATH}/square_n_sum)
include_directories(${SOURCE_PATH}/reversed_strings)
include_directories(${IGLOO_PATH})

file(GLOB TEST_FILES CONFIGURE_DEPENDS tests/*.cpp src/**/*.cpp)
#file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/**/*.cpp" "src/**/*.h")

#add_executable(codewars ${SRC_FILES})
#add_executable(reversed-strings src/reversed_strings/reversed_strings.cpp)
add_executable(codewars-test ${TEST_FILES})
