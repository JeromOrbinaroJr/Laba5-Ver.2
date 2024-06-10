cmake_minimum_required(VERSION 3.10)
project(Laba5 Ver.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyExecutable Student.h List.h Stack.h main.cpp Student.cpp)