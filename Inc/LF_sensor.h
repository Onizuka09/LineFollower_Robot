/* 
 * this is a driver interface for the line follower sensor (TCRT500) 
 * */

#ifndef LF_SENSOR_H_
#define LF_SENSOR_H_
#include <stdint.h>
typedef enum {
on_line=0,
on_left,
on_right,


}Robot_pos; 
typedef enum{
    black=0,
    white=1,
}sensor_state;

void init_sensor(uint8_t size, uint8_t* arr);
void read_sensor(uint8_t size, uint8_t* arr); 
Robot_pos robot_position(uint8_t size, uint8_t* arr); 




#endif
