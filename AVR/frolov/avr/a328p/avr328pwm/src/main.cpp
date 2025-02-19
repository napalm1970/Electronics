// CTC - Clear Timer on Compare match

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void timer8bit_pwm(void) {
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // Fast PWM mode.
  TCCR0B |= (1 << CS00) | (1 << CS01);   //| (1 << CS20); // Prescaler 64
  TCCR0A |= (1 << COM0A1);               //  Non invertiing mode..

  DDRD |= (1 << PD6); // Pin OC2 output.
  OCR0A = 10;         // F = (F_CPU/Prescaler)/(OCR+1)*2
}

void timer16bit_fastpwm(void) {
  TCCR1A |= (1 << WGM10) | (1 << WGM11); //  10 bit fast PWM mode.
  TCCR1B |= (1 << WGM12);                // 10 bit fast PWM.

  // TCCR1B |= (1 << CS10); // Prescaler 1.
  // TCCR1B |= (1 << CS11); // Prescaler 8.
  TCCR1B |= (1 << CS10) | (1 << CS11); // Prescaler 64.
  // TCCR1B |= (1 << CS10) | (1 << CS12); // Prescaler 1024.

  // TCCR1A |= (1 << COM1A0) | (1 << COM1A1); //
  TCCR1A |= (1 << COM1A1); //

  DDRB |= (1 << PB1); // Pin OC1A output.
  OCR1A = 512;
}

void timer8bit_phasecorrectpwm(void) {
  TCCR1A |= (1 << COM1A1) | (1 << WGM11) | (1 << WGM10); // | (1 << COM1A0);
  TCCR1B |= (1 << CS10) | (1 << CS12);                   //(1 << WGM13) |
  DDRB |= (1 << PB1);
  OCR1A = 811;
  // ICR1 = 1000;
}
void timer_phasefreqpwm(void) {
  TCCR1A |= (1 << COM1A1); // | (1 << WGM10); // | (1 << COM1A0);
  TCCR1B |= (1 << CS10) | (1 << CS12) | (1 << WGM13);
  OCR1A = 50;
  ICR1 = 200;

  DDRB |= (1 << PB1);
}

ISR(TIMER1_COMPA_vect) {
  if (OCR1A < ICR1) {
    OCR1A += 5;
    _delay_ms(10);
  }

  if (OCR1A == ICR1) {
    OCR1A = 50;
  }
}

int main() {
  // timer8bit_pwm();
  // timer16bit_fastpwm();
  // timer8bit_phasecorrectpwm();

  TIMSK1 |= (1 << OCIE1A);

  timer_phasefreqpwm();

  DDRC = 0x00;
  PORTC = 0xff;
  sei();
  while (1) {
    // if (~PINC & (1 << 0)) {
    //   OCR1A += 5;
    //   _delay_ms(200);
    //   if (OCR1A >= 1018) {
    //     OCR1A = 511;
    //   }
    // }
    //
    // if (~PINC & (1 << 1)) {
    //   OCR1A -= 5;
    //   _delay_ms(200);
    //   if (OCR1A < 0) {
    //     OCR1A = 511;
    //   }
    // }
  }

  return 0;
}
