
// #define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  unsigned char rab;


  TCCR0 |= ((1<<2) | (1<<0)); // Set byte 2 to 1
  // TCCR0 &= ~((1<<0) | (1<<1)); // Reset bytes 0 and 1
  TCCR0 &= ~(1<<1);

  DDRC = 0xFF;
  PORTC = 0xFF;

  DDRD = 0x00;
  PORTD = 0xFF;
  PIND = 0b11111111; 

  ACSR = 0x80;

  while (1) {
    if (PIND == 0b11111111) {
      rab = 0b10000000;
      while (rab != 0) {
        PORTC = rab ^ 0xFF;
        rab = rab >> 1;
        _delay_ms(300);
      }
    } else {
      rab = 0b00000001;
      while (rab != 0) {
        PORTC = rab ^ 0xFF;
        rab = rab << 1;
        _delay_ms(300);
      }
    }
  }

  return 0;
}
