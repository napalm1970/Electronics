
#include <avr/io.h>
#include <util/delay.h>



inline void rigtrunLed(int counter, int timer)
{
  
    for (int i = counter; i > 0; i--) {
      PORTC |= (1 >> i);
      _delay_ms(timer);

      PORTC &= (0 >> i);
    }
}
inline void leftrunLed(int counter, int timer)
{
  
    for (int i = counter; i > 0; i--) {
      PORTC |= (1 << i);
      _delay_ms(timer);

      PORTC &= (0 << i);
    }


    for (int i = counter; i > 0; i--) {
      PORTC |= (1 << i);
      _delay_ms(timer);

      PORTC &= (0 << i);
    }
}
