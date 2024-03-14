#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char *argv[]) {
  DDRA |= (1 << 0);
  PORTA &=~(1<<0);

  while (1) {
    PORTA|= (1<<0);
    _delay_ms(500);
    PORTA&= ~(1<<0);
    _delay_ms(500);
  }

  return 0;
}
