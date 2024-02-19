#ifndef __BSP_USART_H__
#define __BSP_USART_H__


#include <stdint.h>
#include <stdio.h>


void uart1_send(uint8_t *data, uint16_t len);
uint16_t uart1_receive(uint8_t *buff, uint16_t len);
void uart1_init(void);
void bsp_uart_init(void);


#endif
