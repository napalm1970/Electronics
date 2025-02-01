#include <avr/interrupt.h>
#include <avr/io.h>

ISR(TIMER0_OVF_vect) {
  PORTD ^= (1 << PD0);
  PORTD ^= (1 << PD0);
}

void timer_ctc(void) {
  TCCR0A |= (1 << WGM01);              // CTC mode.
  TCCR0B |= (1 << CS00) | (1 << CS01); //| (1 << CS20); // Prescaler 64
  TCCR0A |= (1 << COM0A0);             // Toggle compaare match.

  DDRD |= (1 << PD6); // Pin OC0 output.
  OCR0A = 50;         // F = (F_CPU/Prescaler)/(OCR2+1)*2
}

int main() {
  DDRD |= (1 << PD0) | (1 << PD1); // | (1 << PD1) | (1 << PD2);
  // TCCR0B |= (1 << CS00) | (1 << CS01); // Prescaler 64 TIMER0
  // TIMSK0 |= (1 << TOIE0);
  // TCNT0 = 64;
  timer_ctc();
  // sei();

  while (1) {
  }
  return 0;
}
