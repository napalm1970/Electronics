#include <avr/interrupt.h>
#include <avr/io.h>

ISR(TIMER0_OVF_vect) {
  PORTC ^= (1 << PC0);
  PORTC ^= (1 << PC0);
}

ISR(TIMER1_OVF_vect) {
  PORTC ^= (1 << PC1);
  PORTC ^= (1 << PC1);
  TCNT1 = 49910;
}

ISR(TIMER2_OVF_vect) {
  PORTC ^= (1 << PC2);
  PORTC ^= (1 << PC2);
}

int main() {
  DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
  TCCR0 |= (1 << CS02);                // Prescaler 64 TIMER0
  TCCR2 |= (1 << CS21);                // Prescaler 8 TIMER2
  TCCR1B |= (1 << CS10) | (1 << CS11); // 64 bit prescaler.
  TIMSK |= (1 << TOIE0);
  TIMSK |= (1 << TOIE1);
  TCNT1 = 49910;
  TIMSK |= (1 << TOIE2);

  sei();

  while (1) {
  }
  return 0;
}
