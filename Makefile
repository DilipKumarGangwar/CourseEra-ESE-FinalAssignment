#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
#PLATFORM = 

# Architectures Specific Flags
#LINKER_FILE = msp432p401r.lds

#SPECS = nosys.specs

# Compiler Flags and Defines



ifeq ($(PLATFORM),HOST)
	CC = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map 
	LD = ld
	OBJDUMP = objdump
	
	SIZE = size
	
		
else ifeq ($(PLATFORM),MSP32)
	#compiler flags
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LINKER_FILE= ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
        # Architectures Specific Flags
	CPU = cortex-m4 
	ARCH = thumb
	SPECS = nosys.specs
	FPU = fpv4-sp-d16 
	ARMFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=$(FPU) --specs= $(SPECS) -Wall -DMSP432
	OBJDUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size	
endif

VPATH = ./src

ifeq ($(VERBOSE),VERBOSE)
		VER = -g
endif

#LD = arm-none-eabi-ld
TARGET = finalAssignment
#CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ARMFLAGS)
CFLAGS = -Wall -Werror $(VER) -O0 -std=c99 $(INCLUDEs) -D$(PLATFORM) $(ARMFLAGS) -D$(VERBOSE) -D$(COURSE1)

 

OBJ_FILES=$(SOURCES:.c=.o)

DEPS=$(SOURCES:.c=.d)	
%.i: %.c
	$(CC) -E $(INCLUDES)  $(CFLAGS)  $< -o $@


%.asm: %.c
	$(CC) -S $(INCLUDES)  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(INCLUDES)  $(CFLAGS) -c  $< -o $@ 

#For Dependency Files
%.d: %.c
	$(CC) $(INCLUDES)  $(CFLAGS) -M  $< -o $@ 	

#GENERATE asm file from executable
$(TARGET).asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $(TARGET).asm
	 
.PHONY: compile-all
compile-all: $(OBJ_FILES)
	$(CC) $(INCLUDES) $(CFLAGS) $(OBJ_FILES) -c  -o $(TARGET).o

.PHONY: build
build: $(TARGET).out  $(TARGET).asm

$(TARGET).out: $(OBJ_FILES) $(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(OBJ_FILES) -o $@ 
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
	
.PHONY: clean
clean: 
	rm -f $(OBJ_FILES) $(TARGET).out *.asm *.i *.o *.map *.d

