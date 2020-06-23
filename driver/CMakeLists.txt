cmake_minimum_required (VERSION 3.16)

add_subdirectory(cmsis)
add_subdirectory(hal)

SET(LIB_NAME "drivermainunit")
project(${LIB_NAME})

add_library(${LIB_NAME} 
			hal.cpp
			controlbus.cpp
			birelay.cpp
			version.cpp
)

