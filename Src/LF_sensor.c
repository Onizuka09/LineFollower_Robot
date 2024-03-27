#include "GPIO.h"
#include "LF_sensor.h"
#include "USART2_Debug_dirver.h"
//Line follower pin (5 pins INPUT ) 
//PIN_1 PB12 	=> S1 ( left ) 
//PIN_2 PB2 (	=> S2 
//PIN_3 PB15 (=> S3 middle
//PIN_4 PB14 ()	=> S4 
//PIN_5 PA13 ()	=> S5 middle  

void init_sensor(uint8_t size, uint8_t *arr){

     GPIO_config(GPIOB,PIN_12,INPUT);         
     GPIO_config(GPIOB,PIN_2,INPUT);         
    GPIO_config(GPIOB,PIN_15,INPUT);         
    GPIO_config(GPIOB,PIN_14,INPUT);         
     GPIO_config(GPIOB,PIN_13,INPUT);  
}
void read_sensor(uint8_t size, uint8_t *arr){

    arr[0] = GPIO_PIN_READ(GPIOB,PIN_12);         
    arr[1] = GPIO_PIN_READ(GPIOB,PIN_2);         
    arr[2] = GPIO_PIN_READ(GPIOB,PIN_15);         
    arr[3] = GPIO_PIN_READ(GPIOB,PIN_14);         
    arr[4] = GPIO_PIN_READ(GPIOB,PIN_13);         
	for (int i =0; i<size; i++){
		printf("sensor_%d : %d -- ",i,arr[i]);
	}

	printf("\n\r");

}
/*  
void test_LF_sensor(){
	read_sensor(sensor_arr_size,sensor_arr);
	for (int i =0; i<sensor_arr_size; i++){
		printf("sensor_%d : %d -- ",i,sensor_arr[i]);
	}
	printf("\n\r");
	delay_ms(1000);
}
*/
