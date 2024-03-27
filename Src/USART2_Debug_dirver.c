/*
 * USART_Debug_dirver.c
 *
 *  Created on: Mar 17, 2024
 *      Author: moktar
 */

#include "USART2_Debug_dirver.h"
#include "stm32f4xx.h"


static uint32_t baudrate = 112500;

#define TX_pin 2 //PA2 // AF07
#define RX_pin 3 //PA3 // AF07
#define SYS_FRQ  16000000 // 16Mhr
#define APB1_clk SYS_FRQ
#define GPIOA_RCC_enr ( 1U<<0 )
#define USART2_RCC_enr ( 1U<<17 )
#define USART2_en (1U<<13)
#define CR1_TE ( 1U <<3 )
#define CR1_RE ( 1U <<2 )

/* fucntion definotions */
static uint16_t calculate_baudrate(uint32_t bd,uint32_t periph_clk );

/* */


int __io_putchar(int ch){
	debug_uart_write(ch);
	return ch;
}

static void GPIO_init(uint8_t pin) {


	// MODER Alternate function
	GPIOA->MODER  &= ~(1U<< pin*2 );
	GPIOA->MODER  |= (1U<< ((pin*2)  +1));


	// configure alternate function AF7
	GPIOA->AFR[0] |= (1U<<((pin *4 )) );
	GPIOA->AFR[0] |= (1U<<((pin *4 ) +1) );
	GPIOA->AFR[0] |= (1U<<((pin *4 )+2 ) );
	GPIOA->AFR[0] &= ~(1U<<((pin *4 )+ 3) );
}


void debug_uart_init()
{
	// enable GPIOA
	RCC->AHB1ENR |= GPIOA_RCC_enr ;
	// sett up gpio pin
	GPIO_init(TX_pin);
	GPIO_init(RX_pin);
	/* USART Config */
	// enable colcok access to USARt2
	RCC->APB1ENR |= (USART2_RCC_enr);

	// disable usart
	USART2->CR1 =0 ; // clear the reg
	USART2->CR1 &= ~USART2_en ;
	// setup baudrate
	USART2->BRR = calculate_baudrate(baudrate,APB1_clk);

	// set transfer direction:  fullduplex ( RX and TX )
	USART2->CR1 = CR1_RE | CR1_TE ;
	// Enable USART2 NVIC
    NVIC_EnableIRQ(USART2_IRQn);
	// enable USART2
	USART2->CR1 |= USART2_en ;

}

void debug_uart_write(int data)
{
	// clear data register
	while ( (USART2->SR & SR_TXE) ==0)
	{

	}
	// write to the data register
	USART2->DR  = (data & 0xFF) ;

}
static uint16_t calculate_baudrate(uint32_t bd,uint32_t periph_clk ){


	return ((periph_clk+ (bd/ 2U))/bd) ;
}
