cmake_minimum_required(VERSION 3.21)
project(friendbook C)

set(CMAKE_C_STANDARD 99)

add_executable(friendbook main.c types.h book.h book.c utilities.h utilities.c)
