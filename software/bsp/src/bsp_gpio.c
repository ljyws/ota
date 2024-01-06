#include "bsp_gpio.h"


void bsp_gpio_config(uint32_t gpio_periph, uint32_t pin, uint8_t mode, uint8_t speed)
{
    switch (gpio_periph)
    {
    case GPIOA:
        rcu_periph_clock_enable(RCU_GPIOA);
        break;
    case GPIOB:
        rcu_periph_clock_enable(RCU_GPIOB);
        break;
    case GPIOC:
        rcu_periph_clock_enable(RCU_GPIOC);
        break;
    case GPIOD:
        rcu_periph_clock_enable(RCU_GPIOD);
        break;
    default:
        break;
    }
    
}
