#include "GPIO.h"
// initializes all peripherals: enables RCC clock for peripherals  
// GPIOA ,GPIOB ...,   
void GPIO_init(){
// clock enable 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
// other settings for GPIO conifg PULLUP PULL DOWN ... 
}
// put the timer2 configs here 

// configures the PIN Type 
void GPIO_config(GPIO_TypeDef* GPIOx, PIN_Typedef PIN_x,GPIO_function func){
	uint8_t pin=PIN_x ; 
	switch (func) {
		case OUTPUT:		
			GPIOx->MODER |=(1U<<(pin*2)); 
			GPIOx->MODER &=~(1U<<((pin*2)+1)); 
		break;
		case INPUT:
		// TODO:
			GPIOx->MODER &=~(1U<<(pin*2)); 
			GPIOx->MODER &=~(1U<<((pin*2)+1));
            GPIOx->PUPDR &=~(1U<<(pin*2)); 
			GPIOx->PUPDR |=(1U<<((pin*2)+1));
		break;
		case TIM2_CH1_2:
			GPIOx->MODER &=~(1U<<(pin*2)); 
			GPIOx->MODER |=(1U<<((pin*2)+1)); 
			
		    // set alternate function as AF1
			uint8_t index=0;
			if ( pin < 8) 
				index = 0 ;
			else {
			index = 1;
			pin = pin - 8 ;
			}
		    GPIOx->AFR[index] |= (1U<<(pin*4) ) ; 
		break;
	}
}
bool GPIO_PIN_READ(GPIO_TypeDef* GPIOx, PIN_Typedef pinx){
	return (GPIOx->IDR & (1U<<pinx));
}
void GPIO_PIN_WRITE(GPIO_TypeDef* GPIOx, PIN_Typedef pinx,uint8_t state){
	if (state){
	GPIOx->ODR |= (1U<<pinx);
	}else {
	GPIOx->ODR &=~(1U<<pinx);
	}
}

