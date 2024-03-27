#include "delay.h"
#include "motor.h"
#include "LF_sensor.h"
#include "USART2_Debug_dirver.h"

#define sensor_arr_size 5
// IN1 PB5  (D4)  // output
// IN2 PB4  (D5)   // ouput
// IN3 PB1  (x)  infront of D7 // ouput
// IN4 PB3  (D3)  // output

// ENA PA0 : PWM_timer2_ch1 (A0)  
// ENB PA1 : PWM_timer2_ch2 (A1) 

//Line follower pin (5 pins INPUT ) 
//PIN_1 PA9 (D8)	=> S1 ( left ) 
//PIN_2 PB6 (D10)	=> S2 
//PIN_3 PA7 (D11)	=> S3 middle
//PIN_4 PA6 (D12)	=> S4 
//PIN_5 PA5 (D13)	=> S5 middle  

uint8_t sensor_arr[sensor_arr_size]={0}; 

void test_LF_sensor();

int main(void)
{
	// init GPIOA and B 
	GPIO_init();
	init_sensor(sensor_arr_size,sensor_arr); 
    debug_uart_init(); 

	// motor init 
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


	//right(60,70);

	while (1){
	
        //	forward(90, 90);
        read_sensor(5, sensor_arr);
       // test_LF_sensor();
	   delay_ms(1000);
	}
	


return 0;
}

