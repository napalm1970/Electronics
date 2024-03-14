// #include <cstdint>
#include "stm32f103xb.h"
#include <stm32f1xx.h>

//----------------------------------------------------------
#define LED1_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR2)
#define LED1_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR2)
#define LED2_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR3)
#define LED2_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR3)
#define LED3_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR4)
#define LED3_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR4)
#define LED4_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR5)
#define LED4_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR5)
#define LED5_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR6)
#define LED5_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR6)
#define LED6_ON() SET_BIT(GPIOA->ODR,GPIO_ODR_ODR7)
#define LED6_OFF() CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR7)
#define LED7_ON() SET_BIT(GPIOB->ODR,GPIO_ODR_ODR0)
#define LED7_OFF() CLEAR_BIT(GPIOB->ODR,GPIO_ODR_ODR0)
#define LED8_ON() SET_BIT(GPIOB->ODR,GPIO_ODR_ODR1)
#define LED8_OFF() CLEAR_BIT(GPIOB->ODR,GPIO_ODR_ODR1)
#define LED9_ON() SET_BIT(GPIOB->ODR,GPIO_ODR_ODR10)
#define LED9_OFF() CLEAR_BIT(GPIOB->ODR,GPIO_ODR_ODR10)
#define LED10_ON() SET_BIT(GPIOB->ODR,GPIO_ODR_ODR11)
#define LED10_OFF() CLEAR_BIT(GPIOB->ODR,GPIO_ODR_ODR11)
//----------------------------------------------------------
__IO uint32_t tmpreg;
// uint8_t time2_count = 0;

inline void delay(__IO uint32_t tck) {
  while (tck) {
    tck--;
  }
}

void RCC_DeInit(void) {
  SET_BIT(RCC->CR, RCC_CR_HSION);
  while (READ_BIT(RCC->CR, RCC_CR_HSERDY != RCC_CR_HSERDY)) {
  }
  MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, 0x80U);
  CLEAR_REG(RCC->CFGR);
  while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RESET) {
  }
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
  while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RESET) {
  }
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON | RCC_CR_CSSON);
  while (READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET) {
  }
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);
}

int main(void) {
  RCC_DeInit();
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN); 
  tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);
  //NOJTAG: JTAG-DP Disabled and SW-DP Enabled 
  CLEAR_BIT(AFIO->MAPR,AFIO_MAPR_SWJ_CFG);
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SWJ_CFG_JTAGDISABLE);
  return 0;
}