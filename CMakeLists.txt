cmake_minimum_required(VERSION 3.5)
project("Data Structures And Algorithms In C++")

set(EXTERNALS_DIR externals)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14 -pthread")

add_subdirectory("${EXTERNALS_DIR}/googletest")

enable_testing()
add_subdirectory(test)