#include <avr/io.h>
#include <util/delay.h>

void initport(int i) {
  switch (i) {
  case 0:
    PORTC = 0b00111111;
    break;
  case 1:
    PORTC = 0b00000110;
    break;
  case 2:
    PORTC = 0b01011011;
    break;
  case 3:
    PORTC = 0b01001111;
    break;
  case 4:
    PORTC = 0b01100110;
    break;
  case 5:
    PORTC = 0b01101101;
    break;
  case 6:
    PORTC = 0b01111101;
    break;
  case 7:
    PORTC = 0b00000111;
    break;
  case 8:
    PORTC = 0b01111111;
    break;
  case 9:
    PORTC = 0b01101111;
    break;
  default:
    break;
  }
}

int main(int argc, char *argv[]) {
  DDRC = 0b11111111;
  PORTC = 0x00;
  int dig[10] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
                 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
  while (1) {
    for (int i = 0; i < 9; i++) {
      initport(i);
      // PORTC = dig[i];
      _delay_ms(19000);
    }
  }

  return 0;
}
