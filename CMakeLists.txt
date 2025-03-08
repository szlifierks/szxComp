cmake_minimum_required(VERSION 3.30)
project(compilerxd)

set(CMAKE_CXX_STANDARD 20)

add_executable(compilerxd main.cpp
        Lexer.cpp
        Lexer.h
        Kompilator.cpp
        Kompilator.h)
