cmake_minimum_required(VERSION 3.14)
project(statemachine)

add_library(
    statemachine
    ${CMAKE_CURRENT_SOURCE_DIR}/statemachine.c
)
