#include <avr/io.h>
#include <util/delay.h>
// #include "led.h"

int main() {

  DDRC = 0b11111111;

  while (1) {
    PORTC = 0b00000001;
    for (int i = 0; i <= 7; i++) {
      PORTC |= (1 << i);
      _delay_ms(20);

      PORTC &= (0 << i);
    }

    PORTC = 0b10000000;
    for (int i = 7; i > 0; i--) {
      PORTC |= (1 << i);
      _delay_ms(20);
    }

    // leftrunLed(7, 50);
    // rigtrunLed(7, 50);
  }

  return 0;
}
