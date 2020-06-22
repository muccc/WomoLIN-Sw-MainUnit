SET(LIB_NAME "cmsis")
project(${LIB_NAME})

include_directories(../inc ../../hal/inc ../../../inc)

set(CMAKE_C_FLAGS "-DSTM32L476xx -DUSE_HAL_DRIVER -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -fdata-sections -ffunction-sections")

enable_language(ASM)

add_library(${LIB_NAME}
	system_stm32l4xx.c
	../../startup_stm32l476xx.s
)
