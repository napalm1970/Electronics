DEVICE=m16
MCU=atmega16
# Clock speed used (after divider), mostly for delay functions
CLK=1000000
# Name of project output file
PROJ=timer1
# List of source files
SOURCES=main.cpp

# List of object files generated from source files
OBJ=$(SOURCES:.cpp=.o)

all: $(PROJ).hex

# Generated object files
.cpp.o:
	avr-gcc -ggdb3 -w -Os -DF_CPU=$(CLK) -mmcu=$(MCU) -c -o $@ $<

# Generate executable
$(PROJ).elf: $(OBJ)
	avr-gcc -ggdb3 -w -mmcu=$(MCU) $(OBJ) -o $(PROJ).elf

# Create Intel hex format for programming
$(PROJ).hex: $(PROJ).elf
	avr-objcopy -O ihex -R .eeprom $(PROJ).elf $(PROJ).hex

clean:
	rm -f *.hex *.elf *.o

# Install flashes the code
install:
	avrdude -c  usbasp -p $(DEVICE) -B 4 -U flash:w:$(PROJ).hex
