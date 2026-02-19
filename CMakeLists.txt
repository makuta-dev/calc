cmake_minimum_required(VERSION 4.1)
project(calc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(calc
        src/calc/AST.cpp
        src/calc/AST.h
        src/calc/Lexer.cpp
        src/calc/Lexer.h
        src/calc/Token.cpp
        src/calc/Token.h
        src/calc/Parser.cpp
        src/calc/Parser.h
        src/calc/Word.cpp
        src/calc/Word.h

        src/main.cpp
)

target_include_directories(calc PRIVATE src)