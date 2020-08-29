SET(LIB_NAME "board")
project(${LIB_NAME})

include_directories(../hw ../cmsis/inc ../hal/inc ./ext)

add_library(${LIB_NAME}
	version.cpp
	controlbus.cpp
	birelay.cpp
	extrelay.cpp
	relaydrv.cpp
	bme680.cpp
	bme680drv.cpp
	led.cpp
	ext/bme680.c
)
