cmake_minimum_required(VERSION 3.24)
project(App C)

set(CMAKE_C_STANDARD 99)

add_executable(App main.c stack/stack.h stack/stack.c program/program.h program/program.c)
