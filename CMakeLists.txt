cmake_minimum_required (VERSION 3.16)

#TODO
#SET(CMAKE_C_COMPILER "/usr/bin/gcc-9" )
#SET(CMAKE_CXX_COMPILER "/usr/bin/g++-9" )

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror=pedantic -Wextra")

SET(PROJECT_NAME "mainunit")
project(${PROJECT_NAME})

include_directories( ./ )
include_directories( ./../ )

add_subdirectory(siguni)
add_subdirectory(driver)

add_executable(${PROJECT_NAME}
   main
   manager
)

target_link_libraries (${PROJECT_NAME} siguni drivermainunit)

