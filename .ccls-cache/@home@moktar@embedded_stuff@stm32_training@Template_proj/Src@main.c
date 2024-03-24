// #include <stm32f4xx.h>
// #include <stm32f401xe.h>
#include "led.h"


void do_somthing(int i){
i++; 
i=i*2;
}

int main(void)
{
    Led_init();
    TurOn_led();
	while (1)
		{
			Toggle_led();
			for (int i = 0; i < 100000; i++)
			{
				do_somthing(i);		
			}
		}
return 0;
}
