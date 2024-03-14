MCU=atmega16
 # Clock speed used (after divider), mostly for delay functions
 CLK=1000000
 # Name of project output file
 PROJ=extinterupt
 # List of source files
 SOURCES=main.cpp
 
 # List of object files generated from source files
 OBJ=
 
 all: .hex
 
 # Generated object files
 .c.o:
 	 avr-gcc -g -w -Os -DF_CPU= -mmcu= -c -o test1 ATmega16 $< 
 # Generate executable
 .elf: 
 	 avr-gcc -g -w -mmcu= -o .elf
 
 # Create Intel hex format for programming
 .hex: .elf
 	 avr-objcopy -O ihex -R .eeprom .elf .hex
 
 clean:
 	 rm -f *.hex *.elf *.o
 
 # Install flashes the code
 install:
 	 avrdude -c usbasp -p -U flash:w:.hex

