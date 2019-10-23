################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/system_psoc6_cm4.c 

OBJS += \
./psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/system_psoc6_cm4.o 

C_DEPS += \
./psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/system_psoc6_cm4.d 


# Each subdirectory must supply rules for building sources it contributes
psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/%.o: ../psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCY8C624ABZI_D44 -DDEBUG -DAPP_NAME='"SDHC_write_read_cm4"' -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/include" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/cmsis/include" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/include" -I"E:\Programming\Cypress\PSoC6\SDHC_write_read_mainapp/GeneratedSource" -I"E:\Programming\Cypress\PSoC6\SDHC_write_read_mainapp/Source" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/source" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_low" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_high" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/linker/cm4" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io/user" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io" -I"C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/cm0p/prebuilt" -std=gnu11 -mfpu=fpv4-sp-d16 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


