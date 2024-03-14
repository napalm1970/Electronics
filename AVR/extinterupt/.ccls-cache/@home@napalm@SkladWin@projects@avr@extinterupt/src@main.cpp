#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>


ISR(INT0_vect)
{
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
}

int main(int argc, char *argv[]) {
  GICR = 0b11000000;
  MCUCR = 0b00000010;
  SREG |= (1 << 7); // Set bite 7. Enable all global intrupts.

  DDRC = 0xFF;
  PORTC = 0x00;

  DDRD |= (1 << 0);   // Set bite 0 to 1
  PORTD &= ~(1 << 0); // Reset bite 0 to 0
  DDRD &= ~((1 << 2) | (1 << 7));
  PORTD |= (1 << 2) | (1 << 7);

  while (1) {
    PORTC = 0b00000000;
    _delay_ms(500);

    for (int i = 0; i < 8; i++) {
      PORTC |= (1 << i);
      _delay_ms(500);
    }

    if (~PIND & (1 << 7)) {
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
      PORTD |= (1 << 0);
      _delay_ms(150);
      PORTD &= ~(1<<0);
      _delay_ms(150);
    }
  }

  return 0;
}
