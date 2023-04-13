cmake_minimum_required(VERSION 3.23)
project(TADGrafo C)

set(CMAKE_C_STANDARD 99)

add_executable(TADGrafo main.c graph.c graph.h stack.c stack.h)
