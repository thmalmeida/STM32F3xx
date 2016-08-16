################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/_write.c \
../src/glcd.c \
../src/graphics.c \
../src/graphs.c \
../src/pcd8544.c \
../src/rgi.c \
../src/stm32f30x_it.c \
../src/stm32f3_discovery.c \
../src/text.c \
../src/text_tiny.c \
../src/timers.c \
../src/usart.c 

CPP_SRCS += \
../src/main.cpp 

OBJS += \
./src/_write.o \
./src/glcd.o \
./src/graphics.o \
./src/graphs.o \
./src/main.o \
./src/pcd8544.o \
./src/rgi.o \
./src/stm32f30x_it.o \
./src/stm32f3_discovery.o \
./src/text.o \
./src/text_tiny.o \
./src/timers.o \
./src/usart.o 

C_DEPS += \
./src/_write.d \
./src/glcd.d \
./src/graphics.d \
./src/graphs.d \
./src/pcd8544.d \
./src/rgi.d \
./src/stm32f30x_it.d \
./src/stm32f3_discovery.d \
./src/text.d \
./src/text_tiny.d \
./src/timers.d \
./src/usart.d 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_ITM -DSTM32F30X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f3-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C++ Compiler'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_ITM -DSTM32F30X -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f3-stdperiph" -std=gnu++11 -fabi-version=0 -fno-exceptions -fno-rtti -fno-use-cxa-atexit -fno-threadsafe-statics -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


