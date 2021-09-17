cmake_minimum_required(VERSION 3.20)
project(LMP1)

set(CMAKE_CXX_STANDARD 23)

add_executable(LMP1 main.cpp src/Node.cpp src/Node.h src/List.cpp src/List.h)
