#include "motor.h"
void forward(uint8_t speedM1, uint8_t speedM2)
{
    GPIO_PIN_WRITE(GPIOB, IN3_ML, 0);
    GPIO_PIN_WRITE(GPIOB, IN4_ML, 1);

    GPIO_PIN_WRITE(GPIOB, IN2_MR, 0);
    GPIO_PIN_WRITE(GPIOB, IN1_MR, 1);

    set_dutyCycle_ch1(TIM2, speedM1);
    set_dutyCycle_ch2(TIM2, speedM2);
}
void backward(uint8_t speedM1, uint8_t speedM2)
{
    GPIO_PIN_WRITE(GPIOB, IN3_ML, 1);
    GPIO_PIN_WRITE(GPIOB, IN4_ML, 0);

    GPIO_PIN_WRITE(GPIOB, IN2_MR, 1);
    GPIO_PIN_WRITE(GPIOB, IN1_MR, 0);

    set_dutyCycle_ch1(TIM2, speedM1);
    set_dutyCycle_ch2(TIM2, speedM2);
}
void left(uint8_t speedM1, uint8_t speedM2)
{

    GPIO_PIN_WRITE(GPIOB, IN3_ML, 1);
    GPIO_PIN_WRITE(GPIOB, IN4_ML, 0);

    GPIO_PIN_WRITE(GPIOB, IN2_MR, 0);
    GPIO_PIN_WRITE(GPIOB, IN1_MR, 1);

    set_dutyCycle_ch1(TIM2, speedM1);
    set_dutyCycle_ch2(TIM2, speedM2);
}
void right(uint8_t speedM1, uint8_t speedM2 )
{
    GPIO_PIN_WRITE(GPIOB, IN3_ML, 0);
    GPIO_PIN_WRITE(GPIOB, IN4_ML, 1);

    GPIO_PIN_WRITE(GPIOB, IN2_MR, 1);
    GPIO_PIN_WRITE(GPIOB, IN1_MR, 0);

    set_dutyCycle_ch1(TIM2, speedM1);
    set_dutyCycle_ch2(TIM2, speedM2);
}
void stop(){

    GPIO_PIN_WRITE(GPIOB, IN3_ML, 0);
    GPIO_PIN_WRITE(GPIOB, IN4_ML, 0);

    GPIO_PIN_WRITE(GPIOB, IN2_MR, 0);
    GPIO_PIN_WRITE(GPIOB, IN1_MR, 0);

    set_dutyCycle_ch1(TIM2, 0);
    set_dutyCycle_ch2(TIM2, 0);
}
