cmake_minimum_required(VERSION 3.17)
project(Shell)

set(CMAKE_C_STANDARD 99)

add_executable(Shell
        LICENSE
        README.md source/main.c source/shell.c header/shell.h source/arg_list.c header/arg_list.h source/builtin_ls.c header/builtin_ls.h header/builtin_echo.h source/builtin_echo.c header/builtin_cat.h source/builtin_cat.c)

