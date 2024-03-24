#include "led.h"
#include "delay.h"
#include "motor.h"
// IN1 PB5  (D4)  // output
// IN2 PB4  (D5)   // ouput
// IN3 PB1  (x)  infront of D7 // ouput
// IN4 PB3  (D3)  // output

// ENA PA0 : PWM_timer2_ch1 (A0)  
// ENB PA1 : PWM_timer2_ch2 (A1) 



int main(void)
{
	// init GPIOA and B 
	GPIO_init();
	GPIO_config(GPIOA, PIN_5, OUTPUT);
	GPIO_PIN_WRITE(GPIOA, PIN_5, 1);

	GPIO_config(GPIOB, IN3_ML, OUTPUT);
	

	GPIO_config(GPIOB, IN4_ML, OUTPUT);
	

	GPIO_config(GPIOB, IN2_MR, OUTPUT);
	

	GPIO_config(GPIOB, IN1_MR, OUTPUT);
	

	TIMER2_init(16,100 );
	GPIO_config(GPIOA,ENA_MR,TIM2_CH1_2);
	GPIO_config(GPIOA,ENB_ML,TIM2_CH1_2);
	PWM_channel_1_config(TIM2);
	PWM_channel_2_config(TIM2);
	right(60,70);

	while (1){
		forward(90, 90);

		GPIO_PIN_WRITE(GPIOA, PIN_5, 1);

	delay_ms(3000);
	stop();
	// set_dutyCycle_ch1(TIM2, 0);
	// set_dutyCycle_ch2(TIM2,0);
	// 	GPIO_PIN_WRITE(GPIOA, PIN_5, 0);
	delay_ms(5000);
	}
	


return 0;
}
