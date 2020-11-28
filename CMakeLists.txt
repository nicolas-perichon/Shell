cmake_minimum_required(VERSION 3.17)
project(Shell)

set(CMAKE_C_STANDARD 99)

add_executable(Shell
        LICENSE
        README.md source/main.c source/shell.c header/shell.h)
