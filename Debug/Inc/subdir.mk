################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/adc.c \
../Inc/usart.c 

OBJS += \
./Inc/adc.o \
./Inc/usart.o 

C_DEPS += \
./Inc/adc.d \
./Inc/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F303K8Tx -DNUCLEO_F303K8 -DSTM32F3 -c -I../Inc -I"C:/Users/marei/Documents/Embedded/STM32/STM32Cube_FW_F3_V1.11.0/Drivers/CMSIS/Include" -I"C:/Users/marei/Documents/Embedded/STM32/STM32Cube_FW_F3_V1.11.0/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/adc.d ./Inc/adc.o ./Inc/adc.su ./Inc/usart.d ./Inc/usart.o ./Inc/usart.su

.PHONY: clean-Inc

