#include "timer.h"
#include "stm32f401xe.h"
uint8_t max_duty_cycle =0; 
#define CR1_CEN (1U << 0) // enable timer2
#define CR1_APRE (1U<<7)
#define CR1_CMS ((1U<< 5) | (1U<< 6))
#define CR1_DIR (1U<<4)
#define EGR_UG ( 1U<<0)


#define CCER_CC1E (1U << 0)
#define CCMR_OC1Mpwm (6U << 4)
#define CCMR_OC1PE (1U<<3)

#define CCER_CC2E (1U << 4)
#define CCMR_OC2Mpwm (6U << 12)
#define CCMR_OC2PE (1U << 11)

void TIMER2_init(uint8_t prescaler, uint8_t period){

    /* timer2 configuration  */
    // enable clock access to timer2
     RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
	// set prescaler 
	 TIM2->PSC = prescaler-1;  // 16 MHz / 1600 = 10,000 Hz
    // set auto reload value
    TIM2->ARR = period - 1; // 10,000 Hz / 10,000  = 1 Hz (1 s)    
    max_duty_cycle = period; 
    // reset counter value
    TIM2->CNT = 0;
    // edge eligned mode
    TIM2->CR1 &= ~CR1_CMS;
    // direction DIR (upcount)
    TIM2->CR1 &= ~CR1_DIR ; 
    // enable APRE ( Reload register) for safety ( recommending because it introduces a smooth transitionning when changing the PWM periods ARR)
    TIM2->CR1 |= CR1_APRE; 
    // EGR enable (UG) update generation is enabled (ensures synchronizing the udpate events ( reinializes the timer and update associated register ARR and other control registers ))
    TIM2->EGR |= EGR_UG;
    // enable timer
    TIM2->CR1 |= CR1_CEN;

}


void PWM_channel_1_config(TIM_TypeDef* TIMx){
	// set duty cycle to 0 
    TIMx->CCR1 = 50;
	// preload enable (this en) for safety ( when updating the CCR value, the changed won't take effect immediatly but it will take when an udpate event has taken in place the update event could be specified by software or when the counter reacghes maximum overflows and wraps arround)
    TIMx->CCMR1 |= CCMR_OC1PE;
    // set pwm mode (mode 1) 110
    TIMx->CCMR1 |= CCMR_OC1Mpwm;
	
    // enable compare mode in tim2_ch1
    TIMx->CCER |= CCER_CC1E;
}

void PWM_channel_2_config(TIM_TypeDef* TIMx ){

	TIMx->CCER |= CCER_CC2E;
	TIMx->CCMR1 |= CCMR_OC2PE;
    TIMx->CCMR1 |= CCMR_OC2Mpwm;
	TIMx->CCR2=0 ;  
}
void set_dutyCycle_ch1(TIM_TypeDef* TIMx, uint8_t speed){
    if ( speed > max_duty_cycle)
        speed = max_duty_cycle;
    TIMx->CCR1 = speed;
}
void set_dutyCycle_ch2(TIM_TypeDef* TIMx, uint8_t speed){
    if (speed > max_duty_cycle)
        speed = max_duty_cycle;
    TIMx->CCR2 = speed; 	
}
