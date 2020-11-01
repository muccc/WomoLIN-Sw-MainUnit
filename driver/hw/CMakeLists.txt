SET(LIB_NAME "hw")
project(${LIB_NAME})

include_directories(../hal/inc ../cmsis/inc ../hw ../board)

add_library(${LIB_NAME}
	#stm32l4xx_hal_msp.cpp
	gpio.cpp
	uart.cpp
	spi.cpp
	i2c.cpp
	lin.cpp
)