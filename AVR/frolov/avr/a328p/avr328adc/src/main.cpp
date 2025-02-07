// CTC - Clear Timer on Compare match

#include <avr/io.h>

void timer_ctc(void) {
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM mode.
  TCCR0B |= (1 << CS00) | (1 << CS01);   //| (1 << CS20); // Prescaler 64
  TCCR0A |= (1 << COM0A1);               //  Non invertiing mode..

  DDRD |= (1 << PD6); // Pin OC2 output.
  OCR0A = 10;         // F = (F_CPU/Prescaler)/(OCR2+1)*2
}

int main() {
  timer_ctc();

  while (1) {
  }
  return 0;
}
