cmake_minimum_required(VERSION 4.0)
project(Lab_6 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab_6
        main.c
        trains.c
        trains.h)
