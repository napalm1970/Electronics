#include <avr/interrupt.h>
#include <avr/io.h>

ISR(TIMER0_COMP_vect) { PORTC ^= (1 << PC0); }

ISR(TIMER0_OVF_vect) { PORTC ^= (1 << PC2); }

int main() {

  DDRC |= (1 << PC0) | (1 << PC2);
  // TCCR0 |= (1 << WGM00) | (1 << WGM01); // Fast PWM.
  // TCCR0 |= (1 << WGM01); // CTC mode.
  TCCR0 |= (1 << WGM00); // PWM, Phase Correct.

  TCCR0 |= (1 << CS00) | (1 << CS01); // Prescaaler 64.
  TIMSK |= (1 << OCIE0);              // Enable compare interupt.
  TIMSK |= (1 << TOIE0);              // Enable compare interupt.
  OCR0 = 10;

  sei();

  while (1) {
  }
  return 0;
}
