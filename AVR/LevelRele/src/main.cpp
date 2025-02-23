#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define MIN_LEVEL PD2
#define MAX_LEVEL PD3
#define RELE_ON PC2
#define LED PC3

ISR(TIMER1_OVF_vect) {
  PORTC ^= (1 << LED);
  // PORTC ^= (1 << LED);
  TCNT1 = 32767;
}

ISR(INT0_vect) { PORTC |= (1 << RELE_ON); }

ISR(INT1_vect) { PORTC &= ~(1 << RELE_ON); }

int main() {
  DDRC = 0b00001100;
  PORTC &= ~((1 << MIN_LEVEL) | (1 << MAX_LEVEL) | (1 << RELE_ON));
  PORTC |= (1 << LED);

  TCCR1B |= (1 << CS12); // | (1 << CS00);
  TIMSK |= (1 << 2);

  MCUCR |= (1 << ISC01) | (1 << ISC11);
  GICR |= (1 << INT0) | (1 << INT1);

  sei();

  while (1) {

    // if (!(PINC & (1 << MIN_LEVEL))) {
    //   PORTC |= (1 << RELE_ON);
    // }
    // if (!(PINC & (1 << MAX_LEVEL))) {
    //   PORTC &= ~(1 << RELE_ON);
    // }
  }

  return 0;
}
