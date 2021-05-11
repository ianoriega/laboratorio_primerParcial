################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LABORATORIO_parcial_Uno.c \
../src/arr.c \
../src/barbijos.c \
../src/cliente.c \
../src/compra.c \
../src/cuits.c \
../src/matOp.c \
../src/utn.c 

OBJS += \
./src/LABORATORIO_parcial_Uno.o \
./src/arr.o \
./src/barbijos.o \
./src/cliente.o \
./src/compra.o \
./src/cuits.o \
./src/matOp.o \
./src/utn.o 

C_DEPS += \
./src/LABORATORIO_parcial_Uno.d \
./src/arr.d \
./src/barbijos.d \
./src/cliente.d \
./src/compra.d \
./src/cuits.d \
./src/matOp.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


