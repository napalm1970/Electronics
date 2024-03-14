/*
  64 * 65535 /( F_CPU)
  64 - Presscaller
  65535 - 16 byte counter
*/

#ifndef F_CPU
#define F_CPU 8000000L
#endif


#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

ISR(TIMER1_COMPA_vect)
{
  // TCCR1B = 0b00000000; // Prescaller 64 byte.

  // for (int i = 0; i < 5; i++)
  // {
    PORTC = 0b00000001;
    _delay_ms(500);
    PORTC = 0x00000000;
    _delay_ms(500);
  // }

  // TCNT1 = 0;     // Set counter.
  // TCCR1B = 0b00000011; // Prescaller 64 byte.
}

int main(void)
{
  DDRC = 0b11111111;
  PORTC = 0b00000000;

  DDRA = 0xFF;
  PORTA = 0b00000000;

  TIMSK |= (1 << OCIE1A);   // set bit 2 overflow interupt enable.
  TCCR1B = 0b00001000; // Prescaller 64 byte.
  OCR1AH = 0b01111010;
  OCR1AL = 0b00010010;
  TCCR1B |= (1<<CS12);
  // TCNT1 = 0;     // Set counter to 0.
  sei();               // Set global interupts.

  while (1)
  {
    for (int i = 0; i <= 7; i++)
    {
      // PORTA |= (1 << i);
      PORTA = 0b11111111;
      _delay_ms(500);
      PORTA = 0b00000000;
      _delay_ms(500);
    }
  }

  return 0;
}
