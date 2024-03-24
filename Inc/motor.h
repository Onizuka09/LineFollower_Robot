#ifndef MOTOR_H_ 
#define MOTOR_H_
#include "timer.h"
#include "GPIO.h"
#include <stdint.h>
#define IN1_MR PIN_5
#define IN2_MR PIN_4
#define IN3_ML PIN_1
#define IN4_ML PIN_3

#define ENA_MR PIN_0
#define ENB_ML PIN_1

void forward(uint8_t speedM1, uint8_t speedM2);
void backward(uint8_t speedM1, uint8_t speedM2);
void left(uint8_t speedM1, uint8_t speedM2) ;
void right(uint8_t speedM1, uint8_t speedM2);
void stop();
#endif