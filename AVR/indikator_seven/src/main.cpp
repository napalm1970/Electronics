#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char *argv[]) {
  DDRD = 0b11111111;
  int dig[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
                 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
  while (1) {
    for (int i = 0; i < 9; i++) {
      PORTD = dig[i];
      _delay_ms(1000);
    }
  }

  return 0;
}
