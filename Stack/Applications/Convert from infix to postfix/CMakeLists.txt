cmake_minimum_required(VERSION 3.24)
project(Convert_from_infix_to_postfix C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(program)

add_executable(Convert_from_infix_to_postfix
        app/main.c
        program/program.c
        program/program.h
        stack/stack.c
        stack.c
        stack.h)
