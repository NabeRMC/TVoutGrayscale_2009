###############################################################################
# Makefile for the project ELJ09
###############################################################################

## General Flags
PROJECT = ELJ09
MCU = atmega328p
TARGET = ELJ09.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=ELJ09.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Include Directories
INCLUDES = -I"D:\work_D\Tool\AVR_work\ELJ09\h" 

## Objects that must be built in order to link
OBJECTS = A_APP_Ini.o SYS_iniPort.o SYS_iniCPU.o SYS_iniINT.o A_SYS_Ini.o CRT_icf1_DBG.o A_CRT_Ini.o SYS_intCRT_ICF1.o SYS_main.o SYS_asy.o SYS_iniWDT.o CRT_OutDataL.o CRT_FitDelay.o APP_blinkLED.o CRT_OutDataH.o A_CSL_Ini.o SYS_iniUSART.o CSL_Set_test_data.o CSL_Clear.o CRT_OutDataCLS.o CRT_SetDataVrL.o CRT_Set_VramLine.o CRT_icf1_GRP160_120.o APP_Display_ram.o APP_htoa.o SYS_iniADC.o SYS_iniPWM2.o APP_Check_sts_CRT.o CSL_Scroll.o APP_Check_cds_in.o APP_Check_sts_SYS.o APP_Sound_CETK.o APP_Sound_Famima.o APP_Sound_Polka.o APP_Set_CSL.o CSL_Blinkl.o CSL_Crear_bar.o CSL_Set_bar_data.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) ELJ09.hex ELJ09.eep ELJ09.lss size

## Compile
A_APP_Ini.o: ../src/C/APP/A_APP_Ini.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniPort.o: ../src/C/SYS/ini/SYS_iniPort.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniCPU.o: ../src/C/SYS/ini/SYS_iniCPU.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniINT.o: ../src/C/SYS/ini/SYS_iniINT.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

A_SYS_Ini.o: ../src/C/SYS/A_SYS_Ini.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CRT_icf1_DBG.o: ../src/C/CRT/CRT_icf1_DBG.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

A_CRT_Ini.o: ../src/C/CRT/A_CRT_Ini.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_intCRT_ICF1.o: ../src/C/SYS/int/SYS_intCRT_ICF1.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_main.o: ../src/C/SYS/SYS_main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_asy.o: ../src/C/SYS/SYS_asy.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniWDT.o: ../src/C/SYS/ini/SYS_iniWDT.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CRT_OutDataL.o: ../src/ASM/CRT_OutDataL.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

CRT_FitDelay.o: ../src/ASM/CRT_FitDelay.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

APP_blinkLED.o: ../src/C/APP/APP_blinkLED.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CRT_OutDataH.o: ../src/ASM/CRT_OutDataH.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

A_CSL_Ini.o: ../src/C/CSL/A_CSL_Ini.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniUSART.o: ../src/C/SYS/ini/SYS_iniUSART.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Set_test_data.o: ../src/C/CSL/CSL_Set_test_data.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Clear.o: ../src/C/CSL/CSL_Clear.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CRT_OutDataCLS.o: ../src/ASM/CRT_OutDataCLS.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

CRT_SetDataVrL.o: ../src/ASM/CRT_SetDataVrL.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

CRT_Set_VramLine.o: ../src/C/CRT/CRT_Set_VramLine.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CRT_icf1_GRP160_120.o: ../src/C/CRT/CRT_icf1_GRP160_120.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Display_ram.o: ../src/C/APP/APP_Display_ram.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_htoa.o: ../src/C/APP/APP_htoa.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniADC.o: ../src/C/SYS/ini/SYS_iniADC.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

SYS_iniPWM2.o: ../src/C/SYS/ini/SYS_iniPWM2.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Check_sts_CRT.o: ../src/C/APP/APP_Check_sts_CRT.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Scroll.o: ../src/C/CSL/CSL_Scroll.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Check_cds_in.o: ../src/C/APP/APP_Check_cds_in.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Check_sts_SYS.o: ../src/C/APP/APP_Check_sts_SYS.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Sound_CETK.o: ../src/C/APP/APP_Sound_CETK.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Sound_Famima.o: ../src/C/APP/APP_Sound_Famima.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Sound_Polka.o: ../src/C/APP/APP_Sound_Polka.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

APP_Set_CSL.o: ../src/C/APP/APP_Set_CSL.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Blinkl.o: ../src/C/CSL/CSL_Blinkl.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Crear_bar.o: ../src/C/CSL/CSL_Crear_bar.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

CSL_Set_bar_data.o: ../src/C/CSL/CSL_Set_bar_data.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) ELJ09.elf dep/* ELJ09.hex ELJ09.eep ELJ09.lss ELJ09.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

