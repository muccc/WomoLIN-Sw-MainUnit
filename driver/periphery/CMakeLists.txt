SET(LIB_NAME "periphery")
project(${LIB_NAME})

include_directories(../hw ../cmsis/inc ../hal/inc ./ext)

add_library(${LIB_NAME}
	hellaibs.cpp
	hellaibs1.cpp
	hellaibs2.cpp
	ibs.cpp
)