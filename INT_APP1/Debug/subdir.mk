################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_prog.c \
../DIO-prog.c \
../INT_prog.c \
../KPD_prog.c \
../TIM0_prog.c \
../main.c 

OBJS += \
./CLCD_prog.o \
./DIO-prog.o \
./INT_prog.o \
./KPD_prog.o \
./TIM0_prog.o \
./main.o 

C_DEPS += \
./CLCD_prog.d \
./DIO-prog.d \
./INT_prog.d \
./KPD_prog.d \
./TIM0_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=4000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


