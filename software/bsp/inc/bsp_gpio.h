#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

#include <stdint.h>
#include <gd32f4xx_gpio.h>
#include <gd32f4xx_rcu.h>

void bsp_gpio_config(uint32_t gpio_periph, uint32_t pin, uint8_t mode, uint8_t speed);

#endif

