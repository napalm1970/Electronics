MCU=atmega128
CLK=1000000
PROJ=girlanda2
SOURCE=main.cpp

OBJ=$(SOURCE:.cpp=.o)

all: $(PROJ).hex

.cpp.o:
	avr-gcc -Wcpp -ggdb -gdwarf-2 -g3 -O0 -DF_CPU=$(CLK) -mmcu=$(MCU) -c -o $@ $<

$(PROJ).elf: $(OBJ)
	avr-gcc -g -w -mmcu=$(MCU) $(OBJ) -o $(PROJ).elf

$(PROJ).hex: $(PROJ).elf
	avr-objcopy -O ihex -R .eeprom $(PROJ).elf $(PROJ).hex

clean:
	rm -f *.hex *.elf *.o\n

# Install flashes the code\n
install:
	avrdude -c usbasp -p $(MCU) -U flash:w:$(PROJ).hex

