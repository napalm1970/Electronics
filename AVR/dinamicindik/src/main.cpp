#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define DIGIT PORTD
#define RAZRJAD PORTB


unsigned int digits[10] = {0x3f, 0x6,  0x5b, 0x4f, 0x66,
                           0x6d, 0x7d, 0x7,  0x7f, 0x6f};

unsigned int razr1 = 0, razr2 = 0, razr3 = 0, razr4 = 0;
unsigned char bc547;

void all_digit(unsigned int razbivka_chisla) {
  razr1 = razbivka_chisla / 1000;
  razr2 = razbivka_chisla % 1000 / 100;
  razr3 = razbivka_chisla % 100 / 10;
  razr4 = razbivka_chisla % 10;
}

ISR(TIMER0_OVF_vect) {
  if (bc547 == 1) {
    RAZRJAD = 0b00000001;
    DIGIT = digits[razr1];
  }
  if (bc547 == 2) {
    RAZRJAD = 0b00000010;
    DIGIT = digits[razr2];
  }
  if (bc547 == 3) {
    RAZRJAD = 0b00000100;
    DIGIT = digits[razr3];
  }
  if (bc547 == 4) {
    RAZRJAD = 0b00001000;
    DIGIT = digits[razr4];
  }
  bc547++;

  if (bc547 > 4) {
    bc547 = 0;
  }
}

int main() {
  DDRD = 0xFF;
  DDRB = 0b00001111;

  RAZRJAD = 0x0;
  DIGIT = 0x3f;

  TCCR0 |= (1 << 1);
  // TCCR0 |= ((1 << 0) | (1 << 2)); // f/1024
  TCCR0 &= ~((1 << 0) | (1 << 2)); // f/8
  TIMSK |= (1 << 0);
  TCNT0 = 0;
  sei();

  while (1) {
    all_digit(1970);
  }

  return 0;
}
