################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/battery.c \
../Core/Src/display.c \
../Core/Src/display_fonts.c \
../Core/Src/main.c \
../Core/Src/modes_of_operation.c \
../Core/Src/motors.c \
../Core/Src/moving_average.c \
../Core/Src/sensors.c \
../Core/Src/sprites.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/vl53l0_init.c 

OBJS += \
./Core/Src/battery.o \
./Core/Src/display.o \
./Core/Src/display_fonts.o \
./Core/Src/main.o \
./Core/Src/modes_of_operation.o \
./Core/Src/motors.o \
./Core/Src/moving_average.o \
./Core/Src/sensors.o \
./Core/Src/sprites.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/vl53l0_init.o 

C_DEPS += \
./Core/Src/battery.d \
./Core/Src/display.d \
./Core/Src/display_fonts.d \
./Core/Src/main.d \
./Core/Src/modes_of_operation.d \
./Core/Src/motors.d \
./Core/Src/moving_average.d \
./Core/Src/sensors.d \
./Core/Src/sprites.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/vl53l0_init.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/projects/minisumo/code/minisumo_miras/Drivers/VL53L0X/core/inc" -I"E:/projects/minisumo/code/minisumo_miras/Drivers/VL53L0X/platform/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/battery.d ./Core/Src/battery.o ./Core/Src/battery.su ./Core/Src/display.d ./Core/Src/display.o ./Core/Src/display.su ./Core/Src/display_fonts.d ./Core/Src/display_fonts.o ./Core/Src/display_fonts.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/modes_of_operation.d ./Core/Src/modes_of_operation.o ./Core/Src/modes_of_operation.su ./Core/Src/motors.d ./Core/Src/motors.o ./Core/Src/motors.su ./Core/Src/moving_average.d ./Core/Src/moving_average.o ./Core/Src/moving_average.su ./Core/Src/sensors.d ./Core/Src/sensors.o ./Core/Src/sensors.su ./Core/Src/sprites.d ./Core/Src/sprites.o ./Core/Src/sprites.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/vl53l0_init.d ./Core/Src/vl53l0_init.o ./Core/Src/vl53l0_init.su

.PHONY: clean-Core-2f-Src

