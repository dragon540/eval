cmake_minimum_required(VERSION 3.24)
project(eval)

set(CMAKE_CXX_STANDARD 17)

add_executable(eval main.cpp lexer.cpp lexer.hpp)
