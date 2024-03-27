#ifndef _USART_DEBUG8DRIVER_H_
#define _USART_DEBUG8DRIVER_H_
#include <stdint.h>

#include <stdio.h>
#define SR_TXE ( 1U<<7 )
#define SR_RXNE ( 1U<<5)


void debug_uart_init();

void debug_uart_write(int data);

int debug_uart_read();

#endif
