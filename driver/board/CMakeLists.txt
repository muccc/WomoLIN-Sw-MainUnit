SET(LIB_NAME "board")
project(${LIB_NAME})

include_directories(../hw ../cmsis/inc ../hal/inc)

add_library(${LIB_NAME}
	version.cpp
	controlbus.cpp
	birelay.cpp
)