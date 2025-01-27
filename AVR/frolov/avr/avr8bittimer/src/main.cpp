#include <avr/interrupt.h>
#include <avr/io.h>

ISR(TIMER0_OVF_vect) { PORTC ^= (1 << PC0); }

ISR(TIMER1_OVF_vect) { PORTC ^= (1 << PC1); }

ISR(TIMER2_OVF_vect) { PORTC ^= (1 << PC2); }

int main() {
  DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
  TCCR0 |= (1 << CS02); // Prescaler 64 TIMER0
  TIMSK |= (1 << TOIE0);

  sei();

  while (1) {
  }
  return 0;
}
