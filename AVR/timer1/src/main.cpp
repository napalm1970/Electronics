#define F_CPU 8000000UL

#include <avr/io.h>

int main(int argc, char *argv[]) {

  TCCR1B |= ((1 << CS12) | (1<<CS10)) ;
  TCNT1 = 0x00;
  

  DDRD = 0xFF;
  PORTD = 0x00;

  while (1) {
    if (TCNT1 == 0) {

      PORTD = 0b11111000;
    }
    
    if (TCNT1 == 32768) {

      PORTD = 0xFF;
    }
  }
  return 0;
}
