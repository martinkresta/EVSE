################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Martin/GIT/UHA_COMMON/Src/ADC.c \
C:/Martin/GIT/UHA_COMMON/Src/COM.c \
C:/Martin/GIT/UHA_COMMON/Src/ELM.c \
C:/Martin/GIT/UHA_COMMON/Src/GEST.c \
C:/Martin/GIT/UHA_COMMON/Src/MCAN.c \
C:/Martin/GIT/UHA_COMMON/Src/OW.c \
C:/Martin/GIT/UHA_COMMON/Src/RTC.c \
C:/Martin/GIT/UHA_COMMON/Src/TEMP.c \
C:/Martin/GIT/UHA_COMMON/Src/UI.c \
C:/Martin/GIT/UHA_COMMON/Src/VARS.c \
C:/Martin/GIT/UHA_COMMON/Src/circbuf.c \
C:/Martin/GIT/UHA_COMMON/Src/watchdog.c 

OBJS += \
./Common/Src/ADC.o \
./Common/Src/COM.o \
./Common/Src/ELM.o \
./Common/Src/GEST.o \
./Common/Src/MCAN.o \
./Common/Src/OW.o \
./Common/Src/RTC.o \
./Common/Src/TEMP.o \
./Common/Src/UI.o \
./Common/Src/VARS.o \
./Common/Src/circbuf.o \
./Common/Src/watchdog.o 

C_DEPS += \
./Common/Src/ADC.d \
./Common/Src/COM.d \
./Common/Src/ELM.d \
./Common/Src/GEST.d \
./Common/Src/MCAN.d \
./Common/Src/OW.d \
./Common/Src/RTC.d \
./Common/Src/TEMP.d \
./Common/Src/UI.d \
./Common/Src/VARS.d \
./Common/Src/circbuf.d \
./Common/Src/watchdog.d 


# Each subdirectory must supply rules for building sources it contributes
Common/Src/ADC.o: C:/Martin/GIT/UHA_COMMON/Src/ADC.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/COM.o: C:/Martin/GIT/UHA_COMMON/Src/COM.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/ELM.o: C:/Martin/GIT/UHA_COMMON/Src/ELM.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/GEST.o: C:/Martin/GIT/UHA_COMMON/Src/GEST.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/MCAN.o: C:/Martin/GIT/UHA_COMMON/Src/MCAN.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/OW.o: C:/Martin/GIT/UHA_COMMON/Src/OW.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/RTC.o: C:/Martin/GIT/UHA_COMMON/Src/RTC.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/TEMP.o: C:/Martin/GIT/UHA_COMMON/Src/TEMP.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/UI.o: C:/Martin/GIT/UHA_COMMON/Src/UI.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/VARS.o: C:/Martin/GIT/UHA_COMMON/Src/VARS.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/circbuf.o: C:/Martin/GIT/UHA_COMMON/Src/circbuf.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common/Src/watchdog.o: C:/Martin/GIT/UHA_COMMON/Src/watchdog.c Common/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_FULL_LL_DRIVER -DUSE_HAL_DRIVER -DSTM32L431xx -c -I../../UHA_COMMON/Inc -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common-2f-Src

clean-Common-2f-Src:
	-$(RM) ./Common/Src/ADC.d ./Common/Src/ADC.o ./Common/Src/ADC.su ./Common/Src/COM.d ./Common/Src/COM.o ./Common/Src/COM.su ./Common/Src/ELM.d ./Common/Src/ELM.o ./Common/Src/ELM.su ./Common/Src/GEST.d ./Common/Src/GEST.o ./Common/Src/GEST.su ./Common/Src/MCAN.d ./Common/Src/MCAN.o ./Common/Src/MCAN.su ./Common/Src/OW.d ./Common/Src/OW.o ./Common/Src/OW.su ./Common/Src/RTC.d ./Common/Src/RTC.o ./Common/Src/RTC.su ./Common/Src/TEMP.d ./Common/Src/TEMP.o ./Common/Src/TEMP.su ./Common/Src/UI.d ./Common/Src/UI.o ./Common/Src/UI.su ./Common/Src/VARS.d ./Common/Src/VARS.o ./Common/Src/VARS.su ./Common/Src/circbuf.d ./Common/Src/circbuf.o ./Common/Src/circbuf.su ./Common/Src/watchdog.d ./Common/Src/watchdog.o ./Common/Src/watchdog.su

.PHONY: clean-Common-2f-Src

