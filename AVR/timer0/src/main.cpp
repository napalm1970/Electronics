#define F_CPU 1000000

#include <avr/io.h>

int main(int argc, char *argv[]) {
  DDRD = 0xFF;

  // TCCR0 |= (1<<2); // Set byte 2 to 1
  // TCCR0 &= ~((1<<0) | (1<<1)); // Reset bytes 0 and 1
  TCCR0 = 0b00000101;
  TCNT0 = 0b00000000;

  int z = 0;

  while (1) {
    if (TCNT0 == 255) {
      z++;
      TCNT0 = 0;
    }

    if (z == 10) {
      PORTD = 0b10101010;
    }
    if (z ==20) {
      PORTD = 0xFF;
    }

    if (z ==20) {
      z = 0;
    }
  }

  return 0;
}
