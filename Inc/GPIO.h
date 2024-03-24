

#ifndef  GPIO_H_
#define GPIO_H_
#include "stm32f4xx.h"
#include <stdint.h>
typedef  enum {
    PIN_0 =0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
}PIN_Typedef;
typedef enum{
AF0 = 0U,
AF1,
AF2,
AF3,
AF4,
AF5,
AF6,
AF7,
AF8,
AF9,
AF10,
AF11,
AF12,
AF13,
AF14,
AF15
}AF_types;


typedef enum{
	OUTPUT=16,
	INPUT=17,
	TIM2_CH1_2=AF1,


}GPIO_function;
// initializes all peripherals: enables RCC clock for peripherals  
// GPIOA ,GPIOB ...,   
void GPIO_init(); 

// configures the PIN 
void GPIO_config(GPIO_TypeDef* GPIOx, PIN_Typedef PIN_x,GPIO_function func);

void GPIO_PIN_WRITE(GPIO_TypeDef* GPIOx, PIN_Typedef pinx,uint8_t state); 
#endif 
