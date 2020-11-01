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
	lsm303.cpp
	ibs.cpp
	bme680drv.cpp
	led.cpp
	ext/bme680.c
	lsm303agr.cpp
	lsm303agrmag.cpp
	lsm303agracc.cpp
   hss.cpp
)
