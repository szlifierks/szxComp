cmake_minimum_required(VERSION 3.30)
project(compilerxd)

set(CMAKE_CXX_STANDARD 20)

add_executable(compilerxd main.cpp
        Lexer.cpp
        Lexer.h
        Kompilator.cpp
        Kompilator.h
        Parser.cpp
        Parser.h
        Node.h
        NumNode.h
        OpNode.h
        VarNode.h
        AsgNode.h
        Interpreter.cpp
        Interpreter.h
        AsgNode.cpp
        PrintNode.cpp
        PrintNode.h
        NumNode.cpp
        VarNode.cpp
        OpNode.cpp
        SeqNode.cpp
        SeqNode.h)
