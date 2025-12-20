cmake_minimum_required(VERSION 4.2.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AOC25 C)

add_executable(aoc25)
target_sources(aoc25
    PRIVATE
        src/main.c
)
