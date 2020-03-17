TARGET_NAME := rt-thread

BSP_ROOT ?= ..
RTT_ROOT ?= ../rt-thread

CROSS_COMPILE ?=/usr/bin/arm-none-eabi-

CFLAGS := -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g
AFLAGS := -c -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -x assembler-with-cpp -Wa,-mimplicit-it=thumb  -gdwarf-2
LFLAGS := -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Wl,--gc-sections,-Map=$(TARGET_NAME).map,-cref,-u,Reset_Handler -T $(BSP_ROOT)/board/linker_scripts/link.lds
CXXFLAGS := -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -ffunction-sections -fdata-sections -Dgcc -O0 -gdwarf-2 -g

CPPPATHS :=\
	-I$(BSP_ROOT)/applications \
	-I$(BSP_ROOT)/board \
	-I$(BSP_ROOT)/board/config/Inc \
	-I$(BSP_ROOT)/board/ports \
	-I$(BSP_ROOT)/libraries/HAL_Drivers \
	-I$(BSP_ROOT)/libraries/HAL_Drivers/config \
	-I$(BSP_ROOT)/libraries/STM32F4xx_HAL/CMSIS/Device/ST/STM32F4xx/Include \
	-I$(BSP_ROOT)/libraries/STM32F4xx_HAL/CMSIS/Include \
	-I$(BSP_ROOT)/libraries/STM32F4xx_HAL/STM32F4xx_HAL_Driver/Inc \
	-I$(RTT_ROOT)/components/drivers/include \
	-I$(RTT_ROOT)/components/finsh \
	-I$(RTT_ROOT)/components/libc/compilers/minilibc \
	-I$(RTT_ROOT)/include \
	-I$(RTT_ROOT)/libcpu/arm/common \
	-I$(RTT_ROOT)/libcpu/arm/cortex-m4 

DEFINES := -DHAVE_CCONFIG_H -DRT_USING_MINILIBC -DSTM32F429xx -DUSE_HAL_DRIVER
