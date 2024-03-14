/*
  64 * 65535 /( F_CPU)
  64 - Presscaller
  65535 - 16 byte counter
*/

#ifndef F_CPU
#define F_CPU 1000000L
#endif

#define COUNTER 0

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

ISR(TIMER1_OVF_vect) {
  TCCR1B = 0b00000000; // Prescaller 64 byte.

  for (int i = 0; i < 5; i++) {
    // PORTD = 0b00000000;
    // _delay_ms(200);
    PORTD |= (1 << 0);
    _delay_ms(200);
    PORTD &= ~(1 << 0);
    _delay_ms(200);
  }

  TCNT1 = COUNTER;       // Set counter.
  TCCR1B = 0b00000011; // Prescaller 64 byte.
}

int main(int argc, char *argv[]) {
  DDRA = 0b11111111;
  PORTA = 0b00000000;

  DDRD |= (1 << 0);
  PORTD &= ~(1 << 0);

  TIMSK |= (1 << 2);   // set bit 2 overflow interupt enable.
  TCCR1B = 0b00000011; // Prescaller 64 byte.
  TCNT1 = COUNTER;       // Set counter to 0.
  sei();               // Set global interupts.

  while (1) {
    for (int i = 0; i < 8; i++) {
      PORTA = 0b00000000;
      _delay_ms(200);
      PORTA |= (1 << i);
      _delay_ms(200);
    }
  }

  return 0;
}
