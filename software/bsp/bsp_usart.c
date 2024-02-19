#include "stm32f4xx_hal.h"
#include "bsp_usart.h"
#include "usart.h"
#include "ringbuffer.h"

#define RX_FIFO_SIZE 1024
uint8_t rx_uart1_buffer[RX_FIFO_SIZE];
ring_buffer_t rx_uart1;
uint8_t uasrt1_rxdata;

uint8_t Rx1Buf[128];

void usart1_user_IRQHandler(void)
{
  volatile uint8_t receive;
  if (huart1.Instance->SR & UART_FLAG_RXNE)
  {
    receive = huart1.Instance->DR;
    ring_buffer_queue(&rx_uart1, receive);
  }
}

void bsp_uart_init(void)
{
	uart1_init();
}


void uart1_init(void)
{
	ring_buffer_init(&rx_uart1,rx_uart1_buffer,sizeof(rx_uart1_buffer));
	__HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
}

void uart1_send(uint8_t *data, uint16_t len)
{
	HAL_UART_Transmit_DMA(&huart1, data, len);
}

uint16_t uart1_receive(uint8_t *buff, uint16_t len)
{
	uint16_t readlen = ring_buffer_dequeue_arr(&rx_uart1, buff, len);
  return readlen;
}


