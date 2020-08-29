SET(LIB_NAME "hal")
project(${LIB_NAME})

include_directories(../inc ../../cmsis/inc ../../hw)

set(CMAKE_C_FLAGS "-DSTM32L476xx -DUSE_HAL_DRIVER -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -fdata-sections -ffunction-sections")


add_library(${LIB_NAME}
	stm32l4xx_hal.c
	stm32l4xx_hal_cortex.c
	stm32l4xx_hal_dma.c
	stm32l4xx_hal_dma_ex.c
	stm32l4xx_hal_exti.c
	stm32l4xx_hal_flash.c
	stm32l4xx_hal_flash_ex.c
	stm32l4xx_hal_flash_ramfunc.c
	stm32l4xx_hal_gpio.c
	stm32l4xx_hal_i2c.c
	stm32l4xx_hal_i2c_ex.c
	stm32l4xx_hal_pwr.c
	stm32l4xx_hal_pwr_ex.c
	stm32l4xx_hal_rcc.c
	stm32l4xx_hal_rcc_ex.c
	stm32l4xx_hal_spi.c
	stm32l4xx_hal_spi_ex.c
	stm32l4xx_hal_uart.c
	stm32l4xx_hal_uart_ex.c
)
