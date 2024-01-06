#ifndef __DRV_GPIO_H__
#define __DRV_GPIO_H__

#include <stdint.h>
#include "bsp_gpio.h"

#define PIN_LOW     (0x00)
#define PIN_HIGH    (0x01)

void gpio_regist(uint32_t gpio_periph, uint32_t pin, uint8_t mode);
void gpio_set(uint32_t gpio_periph, uint32_t pin);
uint32_t gpio_get(uint32_t gpio_periph, uint32_t pin);


#endif

