cmake_minimum_required(VERSION 3.20)
project(Liste C)

set(CMAKE_C_STANDARD 99)

add_executable(Liste main.c fcts_listes.h fcts_listes.c)
