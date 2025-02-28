// CTC - Clear Timer on Compare match

#include <avr/io.h>

// void timer_ctc8bit(void) {
//   TCCR0 |= (1 << WGM01); // CTC mode.
//   TCCR0 |= (1 << CS02);  //| (1 << CS20); // Prescaler 64
//   TCCR0 |= (1 << COM00); // Toggle compare match.
//
//   DDRB |= (1 << PB4); // Pin OC0 output.
//   OCR0 = 50;          // F = (F_CPU/Prescaler)/(OCR2+1)*2
// }

void timer_ctc16bit(void) {
  TCCR1B |= (1 << WGM12);              // CTC mode.
  TCCR1B |= (1 << CS10) | (1 << CS12); // Prescaler 64 on timer1.
  TCCR1A |= (1 << COM1A0);             // Toggle compare match.

  DDRB |= (1 << PB1); // Pin OC1A output.
  OCR1A = 50;
  TCCR1A = (uint8_t)511;
}

int main() {
  // timer_ctc8bit();
  timer_ctc16bit();

  while (1) {
  }
  return 0;
}
