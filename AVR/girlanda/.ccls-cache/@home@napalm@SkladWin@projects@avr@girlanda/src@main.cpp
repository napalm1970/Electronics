#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // asm("break");
  DDRC = 0b11111111;

  while (1) {
    PORTC = 0b00000000;
    _delay_ms(1000);

    for (int i = 0; i < 8; i++) {
      PORTC |= (1 << i);
      _delay_ms(500);
    }
  }
}
