
PRO_DIR := .
PROJ_NAME	:= gpio
OUTPUT_PATH := $(PRO_DIR)/output

INC_DIR := $(PRO_DIR)/inc
SRC_DIR := $(PRO_DIR)/src
LINKER_FILE	:= $(PRO_DIR)/linker/stm32f103c8.ld

COMP_DIR := D:/toolbox/GNUArmEmbeddedToolchain/2020-q4-major
PREFIX_GCC_COMPILER	 := arm-none-ebi
CC					 := $(COMP_DIR)/bin/arm-none-eabi-gcc
ASM                  := $(COMP_DIR)/bin/arm-none-eabi-as
LD                   := $(COMP_DIR)/bin/arm-none-eabi-ld

FILE_TO_LINK	:= $(OUTPUT_PATH)/main.o $(OUTPUT_PATH)/startup_stm32f103xb.o

CC_OPT			:= -march=armv7-m -mcpu=cortex-m3 -c -g -mthumb -I$(INC_DIR)
ASM_OPT			:= -march=armv7-m -mcpu=cortex-m3 -c -mthumb 
LD_OPT			:= -T $(LINKER_FILE) -Map $(OUTPUT_PATH)/$(PROJ_NAME).map $(FILE_TO_LINK) -L $(COMP_DIR)/arm-none-eabi/lib/thumb/v7-m/nofp -lc_nano -lnosys -L $(COMP_DIR)/lib/gcc/arm-none-eabi/10.2.1/thumb/v7-m/nofp -lgcc




$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.c
	@echo "compile $(SRC_DIR)/main.c file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.c -o $(OUTPUT_PATH)/main.o

$(OUTPUT_PATH)/startup_stm32f103xb.o: $(SRC_DIR)/startup_stm32f103xb.s
	@echo "compile $(SRC_DIR)/startup_stm32f103xb.s file"
	$(ASM) $(ASM_OPT) $(SRC_DIR)/startup_stm32f103xb.s -o $(OUTPUT_PATH)/startup_stm32f103xb.o

	
build: $(FILE_TO_LINK) $(LINKER_FILE)
	@echo "link object files to create new binary image ($(PROJ_NAME).elf)"
	$(LD) $(LD_OPT) -o $(OUTPUT_PATH)/$(PROJ_NAME).elf
	
	
clean:
	@rm -rf $(OUTPUT_PATH)/*
	

	
	
