cmake_minimum_required (VERSION 3.16)

enable_language(CXX C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(COMPILER_PATH /opt/gcc-arm-none-eabi-9-2019-q4-major/bin/)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Werror=pedantic -Wextra -Wno-ignored-qualifiers -Wno-missing-field-initializers")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSTM32L476xx -DUSE_HAL_DRIVER -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fdata-sections -ffunction-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTM32L476xx -DUSE_HAL_DRIVER -Wall -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fdata-sections -ffunction-sections")

SET(PROJECT_NAME "mainunit")
project(${PROJECT_NAME})

set(EXECUTABLE ${PROJECT_NAME}.elf)

include_directories( ./ )
include_directories( ./../ )
include_directories( ./driver )

add_subdirectory(siguni)
add_subdirectory(driver)


add_executable(${EXECUTABLE}
   main.cpp
   manager.cpp
   driver/hw/stm32l4xx_hal_msp.cpp
   driver/cmsis/src/stm32l4xx_it.cpp
)

target_link_libraries (${EXECUTABLE} siguni drivermainunit cmsis hal hw board periphery)

target_compile_definitions(${EXECUTABLE} PRIVATE
	-DSTM32L476xx
	-DUSE_HAL_DRIVER
)

target_include_directories(${EXECUTABLE} PRIVATE
	driver/cmsis/inc
	driver/hal/inc
	driver/hw
	driver/board
	driver/periphery
)

target_compile_options(${EXECUTABLE} PRIVATE
	-mcpu=cortex-m4
	-mthumb
	-mfpu=fpv4-sp-d16
	-mfloat-abi=hard
	
	-fdata-sections
	-ffunction-sections
	
	-Wall
	
	$<$<CONFIG:Debug>:-Og -gdwarf-2>
)

target_link_options(${EXECUTABLE} PRIVATE
	-T${CMAKE_SOURCE_DIR}/driver/cmsis/STM32L476RGTx_FLASH.ld
	
	-mcpu=cortex-m4
    -mthumb
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -specs=nano.specs
    --specs=rdimon.specs
    -lc
    -lm
    -lnosys
    -Wl,-Map=${PROJECT_NAME}.map,--cref
    -Wl,--gc-sections
)

add_custom_command(TARGET ${EXECUTABLE}
	POST_BUILD
	COMMAND ${COMPILER_PATH}arm-none-eabi-size ${EXECUTABLE}
)

add_custom_command(TARGET ${EXECUTABLE}
	POST_BUILD
	COMMAND ${COMPILER_PATH}arm-none-eabi-objcopy -O ihex ${EXECUTABLE} ${PROJECT_NAME}.hex
	COMMAND ${COMPILER_PATH}arm-none-eabi-objcopy  -O binary -S ${EXECUTABLE} ${PROJECT_NAME}.bin
)
