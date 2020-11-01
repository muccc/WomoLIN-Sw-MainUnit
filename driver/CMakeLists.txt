cmake_minimum_required (VERSION 3.16)

add_subdirectory(cmsis)
add_subdirectory(hal)
add_subdirectory(hw)
add_subdirectory(board)

include_directories(./board ./hw ./hal/inc ./cmsis/inc ./)

SET(LIB_NAME "drivermainunit")
project(${LIB_NAME})

add_library(${LIB_NAME} 
    hal.cpp
)

