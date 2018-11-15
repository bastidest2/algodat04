cmake_minimum_required(VERSION 3.12)
project(algo04)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")

include_directories ("${PROJECT_SOURCE_DIR}")
add_executable(algo04 algo04.cpp binary_tree.cpp)
