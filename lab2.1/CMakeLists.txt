cmake_minimum_required(VERSION 3.20)
project(lab2_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2_1 main.cpp array_processor.h array_processor.cpp)
add_executable(number_generator input_generator.cpp)
