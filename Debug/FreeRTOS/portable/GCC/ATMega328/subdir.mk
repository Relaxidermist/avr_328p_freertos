################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/ATMega328/port.c 

O_SRCS += \
../FreeRTOS/portable/GCC/ATMega328/port.o 

C_DEPS += \
./FreeRTOS/portable/GCC/ATMega328/port.d 

OBJS += \
./FreeRTOS/portable/GCC/ATMega328/port.o 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/ATMega328/%.o: ../FreeRTOS/portable/GCC/ATMega328/%.c FreeRTOS/portable/GCC/ATMega328/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/ingram/eclipse-workspace/spot-micro-avr/FreeRTOS/include -I/home/ingram/eclipse-workspace/spot-micro-avr/Drivers -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


