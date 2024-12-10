cmake_minimum_required(VERSION 3.30)
project(maman11 C)

set(CMAKE_C_STANDARD 11)

add_library(maman11 STATIC letters.c
        xy_bits.c
        letters2.c)
