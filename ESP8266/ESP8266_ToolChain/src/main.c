#include "c_types.h"
#include "gpio.h"
#include "os_type.h"
#include "osapi.h"
#include "user_interface.h"
// #include <driver/uart.h>

static os_timer_t ptimer;

#ifndef __packed
#define __packed __attribute__((__packed__))
#endif

/******************************************************************************
\
 * FunctionName : user_rf_cal_sector_set \
 * Description  : SDK just reversed 4 sectors, used for rf init data and \
 *paramters. We add this function to force users to set rf cal sector, since \
we *don't know which sector is free in user's application. sector map for last \
 *several sectors : ABBBCDDD A : rf cal B : at parameters C : rf init data D : \
 *sdk parameters Parameters   : none Returns      : rf cal sector \
 *******************************************************************************/
uint32 ICACHE_FLASH_ATTR user_rf_cal_sector_set(void) {
  enum flash_size_map size_map = system_get_flash_size_map();
  uint32 rf_cal_sec = 0;

  switch (size_map) {
  case FLASH_SIZE_4M_MAP_256_256:
    rf_cal_sec = 128 - 5;
    break;

  case FLASH_SIZE_8M_MAP_512_512:
    rf_cal_sec = 256 - 5;
    break;

  case FLASH_SIZE_16M_MAP_512_512:
  case FLASH_SIZE_16M_MAP_1024_1024:
    rf_cal_sec = 512 - 5;
    break;

  case FLASH_SIZE_32M_MAP_512_512:
  case FLASH_SIZE_32M_MAP_1024_1024:
    rf_cal_sec = 1024 - 5;
    break;

  case FLASH_SIZE_64M_MAP_1024_1024:
    rf_cal_sec = 2048 - 5;
    break;
  case FLASH_SIZE_128M_MAP_1024_1024:
    rf_cal_sec = 4096 - 5;
    break;
  default:
    rf_cal_sec = 0;
    break;
  }
  return rf_cal_sec;
}

#define LED 2

static uint8_t status = 0;

static void ICACHE_FLASH_ATTR timer_clbc_func(void *arg) {
  status = (status == 0)  ? 1 : 0;
  GPIO_OUTPUT_SET(LED, status);

}

static os_timer_t ptimer;

void ICACHE_FLASH_ATTR user_init(void) {
  gpio_init();
  // Disable WiFi
  wifi_set_opmode(NULL_MODE);
  PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

  gpio_output_set(0, 0, (1 << LED), 0);

  os_timer_disarm(&ptimer);
  os_timer_setfn(&ptimer, (os_timer_func_t *)timer_clbc_func, NULL);
  os_timer_arm(&ptimer, 1000, 1);

  while (1) {
  }
}
