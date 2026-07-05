################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/app.c \
../Core/Src/display.c \
../Core/Src/eeprom.c \
../Core/Src/logger.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/task_actuator.c \
../Core/Src/task_actuator_interface.c \
../Core/Src/task_display.c \
../Core/Src/task_display_interface.c \
../Core/Src/task_sensor.c \
../Core/Src/task_sensor_interface.c \
../Core/Src/task_system.c \
../Core/Src/task_system_interface.c 

OBJS += \
./Core/Src/app.o \
./Core/Src/display.o \
./Core/Src/eeprom.o \
./Core/Src/logger.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/task_actuator.o \
./Core/Src/task_actuator_interface.o \
./Core/Src/task_display.o \
./Core/Src/task_display_interface.o \
./Core/Src/task_sensor.o \
./Core/Src/task_sensor_interface.o \
./Core/Src/task_system.o \
./Core/Src/task_system_interface.o 

C_DEPS += \
./Core/Src/app.d \
./Core/Src/display.d \
./Core/Src/eeprom.d \
./Core/Src/logger.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/task_actuator.d \
./Core/Src/task_actuator_interface.d \
./Core/Src/task_display.d \
./Core/Src/task_display_interface.d \
./Core/Src/task_sensor.d \
./Core/Src/task_sensor_interface.d \
./Core/Src/task_system.d \
./Core/Src/task_system_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app.cyclo ./Core/Src/app.d ./Core/Src/app.o ./Core/Src/app.su ./Core/Src/display.cyclo ./Core/Src/display.d ./Core/Src/display.o ./Core/Src/display.su ./Core/Src/eeprom.cyclo ./Core/Src/eeprom.d ./Core/Src/eeprom.o ./Core/Src/eeprom.su ./Core/Src/logger.cyclo ./Core/Src/logger.d ./Core/Src/logger.o ./Core/Src/logger.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/task_actuator.cyclo ./Core/Src/task_actuator.d ./Core/Src/task_actuator.o ./Core/Src/task_actuator.su ./Core/Src/task_actuator_interface.cyclo ./Core/Src/task_actuator_interface.d ./Core/Src/task_actuator_interface.o ./Core/Src/task_actuator_interface.su ./Core/Src/task_display.cyclo ./Core/Src/task_display.d ./Core/Src/task_display.o ./Core/Src/task_display.su ./Core/Src/task_display_interface.cyclo ./Core/Src/task_display_interface.d ./Core/Src/task_display_interface.o ./Core/Src/task_display_interface.su ./Core/Src/task_sensor.cyclo ./Core/Src/task_sensor.d ./Core/Src/task_sensor.o ./Core/Src/task_sensor.su ./Core/Src/task_sensor_interface.cyclo ./Core/Src/task_sensor_interface.d ./Core/Src/task_sensor_interface.o ./Core/Src/task_sensor_interface.su ./Core/Src/task_system.cyclo ./Core/Src/task_system.d ./Core/Src/task_system.o ./Core/Src/task_system.su ./Core/Src/task_system_interface.cyclo ./Core/Src/task_system_interface.d ./Core/Src/task_system_interface.o ./Core/Src/task_system_interface.su

.PHONY: clean-Core-2f-Src

