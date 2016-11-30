cmake_minimum_required(VERSION 3.6)
project(SudokuGenerator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Driver.cpp Board.cpp Square.cpp)
add_executable(SudokuGenerator ${SOURCE_FILES})