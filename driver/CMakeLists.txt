#add_subdirectory(cmsis)
#add_subdirectory(hal)
cmake_minimum_required (VERSION 3.16)

add_subdirectory(cmsis)
add_subdirectory(hal)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror=pedantic -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -fdata-sections -ffunction-sections")


SET(LIB_NAME "drivermainunit")
project(${LIB_NAME})

add_library(${LIB_NAME} 
			hal.cpp
			controlbus.cpp
			birelay.cpp
			version.cpp
)

