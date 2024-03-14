#include </avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main (int argc, char *argv[])
{
  GICR = 0b11000000;



  return 0;
}
