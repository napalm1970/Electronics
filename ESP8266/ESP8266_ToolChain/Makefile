SRCDIR=/home/napalm/PlatformIO/Projects/ESP8266_ToolChain/src/
SDK=/home/napalm/esp/ESP8266_NONOS_SDK-2.2.1
SDK_INC=$(SDK)/include

XTENSA=/home/napalm/esp/xtensa-lx106-elf
CC:=$(XTENSA)/bin/xtensa-lx106-elf-gcc
AR:=$(XTENSA)/bin/xtensa-lx106-elf-ar
LD:=$(XTENSA)/bin/xtensa-lx106-elf-gcc
SIZE:=$(XTENSA)/bin/xtensa-lx106-elf-size

CC_FLAGS := -g -O0 -std=gnu99 -Wpointer-arith -Wundef -Werror -Wl,-EL \
	-fno-inline-functions -nostdlib -mlongcalls \
	-mtext-section-literals -mno-serialize-volatile -D__ets__ \
	-DICACHE_FLASH -c \
	-I/home/napalm/esp/ESP8266_NONOS_SDK/include/ -I/home/napalm/esp/ESP8266_NONOS_SDK/include/json/ -I include

LD_FLAGS := -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static -Wl,--start-group -lc -lgcc -lphy -lpp -lnet80211 -llwip -lwpa -lmain -lcrypto

ESPTOOL := esptool.py

.PHONY: all clear

all:
	@echo "CC src/main.o"
	@$(CC) -Iinc -I$(SDK_INC) -I$(SDK_INC)/json $(CC_FLAGS) src/main.c -o src/main.o
	@echo "AR build/app_app.a"
	@$(AR) cru build/app_app.a src/main.o
	@echo "LD build/app.out"
	@$(LD) -L$(SDK)/lib -T$(SDK)/ld/eagle.app.v6.ld $(LD_FLAGS) build/app_app.a	-Wl,--end-group -o build/app.out
	@echo "SIZE build/app.out"
	@$(SIZE) build/app.out
	@echo "ESPTOOL build/app.out-0x00000.bin build/app.out-0x10000.bin"
	@$(ESPTOOL) elf2image build/app.out

flash:
	@$(ESPTOOL) write_flash --baud 115200 --no-compress -ff 26m -fm dio -fs detect 0x00000 build/app.out-0x00000.bin 0x10000 build/app.out-0x10000.bin

	# /home/napalm/esp/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc \
	# 	-I/home/napalm/esp/ESP8266_NONOS_SDK/include/ -I/home/napalm/esp/ESP8266_NONOS_SDK/include/json/ -I include \
	# 	-g -O0 -std=gnu99 -Wpointer-arith -Wundef -Werror -Wl, -E -fno-inline-functions -nostdlib \
	# 	-mlongcalls -mtext-section-literals -mno-serialize-volatile -D__ets__ \
	# 	-DCACHE_FLASH -c $(SRCDIR)/main.c -o main.o

	# /home/napalm/esp/xtensa-lx106-elf/bin/xtensa-lx106-elf-ar cru app_app.a main.o

	# /home/napalm/esp/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc -L/home/napalm/esp/ESP8266_NONOS_SDK/lib -T/home/napalm/esp/ESP8266_NONOS_SDK/ld/eagle.app.v6.ld \
 # 	-nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static -Wl,--start-group -lc -lgcc -lphy -lpp -lnet80211 -llwip -lwpa -lmain -lcrypto app_app.a -Wl,--end-group -o app.out

