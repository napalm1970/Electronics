// CTC - Clear Timer on Compare match

#include <avr/io.h>

void timer8bit_ctc(void) {
  TCCR0A |= (1 << WGM01);              // CTC mode.
  TCCR0B |= (1 << CS00) | (1 << CS01); //| (1 << CS20); // Prescaler 64
  TCCR0A |= (1 << COM0A0);             // Toggle compaare match.

  DDRD |= (1 << PD6); // Pin OC2 output.
  OCR0A = 128;        // F = (F_CPU/Prescaler)/(OCR2+1)*2
}

int main() {
  timer8bit_ctc();

  while (1) {
  }
  return 0;
}
