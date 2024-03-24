/*
 * delay.c
 *
 *  Created on: Mar 19, 2024
 *      Author: moktar
 */

#include "stm32f4xx.h"
#define SYSTICK_LOAD_VAl 16000
#define CTRL_CLK ( 1U<<2)
#define CTRL_EN (1U<<0)
#define CTRL_COUNTFLAG ( 1U<<16)

void delay_ms(uint32_t d){
// reload with number of clocks per millisecond
SysTick->LOAD = SYSTICK_LOAD_VAl;
// reset counter falg value
SysTick->VAL = 0;
// set internal clk src
SysTick->CTRL  |= CTRL_CLK;
// enable systick
SysTick->CTRL |= CTRL_EN;

for ( int i =0 ; i< d; i++){
	// wait until the COUNT flag is set to 1  when a timeout has occured
	while ( (SysTick->CTRL & CTRL_COUNTFLAG ) == 0 ){}
}
// reset systick
SysTick->CTRL = 0 ;
}

