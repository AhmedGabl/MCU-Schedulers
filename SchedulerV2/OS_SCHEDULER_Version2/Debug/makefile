################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include OS/subdir.mk
-include MCAL/WDT/src/subdir.mk
-include MCAL/TIMERS/TIMER2/src/subdir.mk
-include MCAL/TIMERS/TIMER1/src/subdir.mk
-include MCAL/TIMERS/TIMER0/src/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
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
LSS += \
OS_SCHEDULER_Version2.lss \

FLASH_IMAGE += \
OS_SCHEDULER_Version2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: OS_SCHEDULER_Version2.elf secondary-outputs

# Tool invocations
OS_SCHEDULER_Version2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,OS_SCHEDULER_Version2.map -mmcu=atmega32 -o "OS_SCHEDULER_Version2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

OS_SCHEDULER_Version2.lss: OS_SCHEDULER_Version2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S OS_SCHEDULER_Version2.elf  >"OS_SCHEDULER_Version2.lss"
	@echo 'Finished building: $@'
	@echo ' '

OS_SCHEDULER_Version2.hex: OS_SCHEDULER_Version2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex OS_SCHEDULER_Version2.elf  "OS_SCHEDULER_Version2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: OS_SCHEDULER_Version2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 OS_SCHEDULER_Version2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) OS_SCHEDULER_Version2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
