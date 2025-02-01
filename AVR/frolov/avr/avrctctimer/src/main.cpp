// CTC - Clear Timer on Compare match

#include <avr/io.h>

void timer_ctc(void) {
  TCCR0 |= (1 << WGM01); // CTC mode.
  TCCR0 |= (1 << CS02);  //| (1 << CS20); // Prescaler 64
  TCCR0 |= (1 << COM00); // Toggle compaare match.

  DDRB |= (1 << PB4); // Pin OC0 output.
  OCR0 = 50;          // F = (F_CPU/Prescaler)/(OCR2+1)*2
}

int main() {
  timer_ctc();

  while (1) {
  }
  return 0;
}
