################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io/subdir.mk
-include psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/gcc/subdir.mk
-include psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/subdir.mk
-include Source/subdir.mk
-include GeneratedSource/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SDHC_write_read_mainapp.elf secondary-outputs

dependents:
	-cd E:/Programming/Cypress/PSoC6/psoc6pdl_Cortex-M4/Debug && $(MAKE) all

# Tool invocations
SDHC_write_read_mainapp.elf: $(OBJS) $(USER_OBJS) E:/Programming/Cypress/PSoC6/psoc6pdl_Cortex-M4/Debug/libpsoc6pdl_Cortex-M4.a
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -T "E:\Programming\Cypress\PSoC6\SDHC_write_read_mainapp/cy8c6xxa_cm4_dual.ld" -Xlinker --gc-sections -Wl,-Map,"SDHC_write_read_mainapp.map" --specs=nano.specs -ffat-lto-objects -g --enable-objc-gc -mfpu=fpv4-sp-d16 -o "SDHC_write_read_mainapp.elf" -Wl,--start-group $(OBJS) $(USER_OBJS) $(LIBS) -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) SDHC_write_read_mainapp.elf
	-@echo ' '

post-build:
	-C:/Users/Oleh/ModusToolbox_1.1/tools/modus-shell-1.0/bin/bash --norc --noprofile C:/Users/Oleh/ModusToolbox_1.1/libraries/psoc6sw-1.1/makefiles/platforms/PSoC6_cm4_dual/cymcuelftool_postbuild.bash C:/Users/Oleh/ModusToolbox_1.1/tools/cymcuelftool-1.0/bin/cymcuelftool E:\Programming\Cypress\PSoC6\SDHC_write_read_mainapp/psoc6_02_cm0p_sleep.elf E:\Programming\Cypress\PSoC6\SDHC_write_read_mainapp/Debug/SDHC_write_read_mainapp.elf ARM_CM4
	-@echo ' '

secondary-outputs:

.PHONY: all clean dependents post-build
E:/Programming/Cypress/PSoC6/psoc6pdl_Cortex-M4/Debug/libpsoc6pdl_Cortex-M4.a:

-include ../makefile.targets
