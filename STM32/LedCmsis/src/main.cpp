#include "stm32f1xx.h"

__IO uint32_t tmpreg;
uint8_t time2_count = 0;

inline void delay(__IO uint32_t tck) {
  while (tck) {
    tck--;
  }
}

int main(void) {
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
  while (1) {
  }

  return 0;
}
