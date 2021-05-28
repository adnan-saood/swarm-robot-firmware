/*
 * __dc_control__.h
 *
 * Created: 5/26/2021 9:18:13 PM
 *  Author: adnan
 */ 
#include <__swarm_wold__.h>

#ifndef __DC_CONTROL___H_
#define __DC_CONTROL___H_

#define MA 1
#define MB 2



extern float _setpoint_a;

int _set_speed(uint8_t motor, int value);

void _break_motor(uint8_t motor);

void _set_setpoint(float value, uint8_t motor);



#endif /* __DC_CONTROL___H_ */