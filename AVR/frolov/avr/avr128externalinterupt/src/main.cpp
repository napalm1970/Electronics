#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

ISR(INT1_vect) { PORTB ^= (1 << PB0); }

int main() {

  // EICRA |= (1 << ISC11); // Nastroika INT1 po spadu
  EICRA |= (1 << ISC11) | (1 << ISC10); // Nastroika INT1 po frontu

  DDRB |= (1 << PB0);
  DDRC |= (1 << PC3);
  sei();
  EIMSK |= (1 << INT1); // Enable INT1

  while (1) {
    PORTC |= (1 << PC3);
    _delay_ms(500);
    PORTC &= ~(1 << PC3);
    _delay_ms(500);
  }
  return 0;
}
