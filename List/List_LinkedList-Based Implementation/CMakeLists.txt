cmake_minimum_required(VERSION 3.24)
project(List_LinkedList_Based_Implementation C)

set(CMAKE_C_STANDARD 99)

add_executable(List_LinkedList_Based_Implementation main.c list/list.c list/list.h ErrorState.h)
