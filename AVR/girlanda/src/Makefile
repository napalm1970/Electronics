MCU=atmega128
# Clock speed used (after divider), mostly for delay functions
CLK=1000000
# Name of project output file
PROJ=girlanda
# List of source files
SOURCES=main.cpp

# List of object files generated from source files
OBJ=$(SOURCES:.cpp=.o)

all: $(PROJ).hex

# Generated object files
.cpp.o:
	avr-gcc -ggdb -gdwarf-2 -g3 -O0 -w -Os -DF_CPU=$(CLK) -mmcu=$(MCU) -c -o $@ $<

# Generate executable
$(PROJ).elf: $(OBJ)
	avr-gcc -g -w -mmcu=$(MCU) $(OBJ) -o $(PROJ).elf

# Create Intel hex format for programming
$(PROJ).hex: $(PROJ).elf
	avr-objcopy -O ihex -R .eeprom $(PROJ).elf $(PROJ).hex

clean:
	rm -f *.hex *.elf *.o

# Install flashes the code
install:
	avrdude -c  usbasp -p $(MCU) -U flash:w:$(PROJ).hex
