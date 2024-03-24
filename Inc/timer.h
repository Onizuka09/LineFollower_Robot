#ifndef TIMER_H_
#define TIMER_H_
#include <stdint.h>
#include"stm32f4xx.h"

void TIMER2_init(uint8_t prescaler, uint8_t period);
void PWM_channel_1_config(TIM_TypeDef* TIMx);
void PWM_channel_2_config(TIM_TypeDef* TIMx);
// set duty cycles 
void set_dutyCycle_ch1(TIM_TypeDef* TIMx,uint8_t speed);
void set_dutyCycle_ch2(TIM_TypeDef* TIMx,uint8_t speed);

#endif
