#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define MIN_LEVEL PB0
#define MAX_LEVEL PB1
#define RELE_ON PB2
#define LED PB3

ISR(TIMER1_OVF_vect) {
  PORTC ^= (1 << LED);
  // PORTC ^= (1 << LED);
  TCNT1 = 32767;
}

int main() {
  DDRC = 0b00001100;
  PORTC &= ~((1 << MIN_LEVEL) | (1 << MAX_LEVEL) | (1 << RELE_ON));
  PORTC |= (1 << LED);

  TCCR1B |= (1 << CS12); // | (1 << CS00);
  TIMSK |= (1 << 2);
  // TCNT1 = 32767;
  sei();

  while (1) {

    if (!(PINC & (1 << MIN_LEVEL))) {
      PORTC |= (1 << RELE_ON);
    } else {
      PORTC &= ~(1 << RELE_ON);
    }
  }

  return 0;
}
