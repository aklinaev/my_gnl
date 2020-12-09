cmake_minimum_required(VERSION 3.17)
project(my_gnl C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(my_gnl
        get_next_line.c
        get_next_line.h
        get_next_line_utils.c
        main.c)
