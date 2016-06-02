# Project definition
cmake_minimum_required(VERSION 3.0)

project("ProjectKPC2S")

# Set the reqired flags from project specification
if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic")
    set(CMAKE_CXX_FLAGS -std=c++11)
endif()

# Define the target executable 
add_executable(prog main.cpp backend.cpp backend.h frontend.cpp frontend.h)

