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

#define DEBUG_CONTROLLER 1

#define K_P     4.0
#define K_I     0.3
#define K_D     0.5



int16_t _ref(uint8_t motor);
void _command(uint8_t motor, int16_t inputValue);
float _sens(uint8_t motor);
int _set_speed(uint8_t motor, int value);
void _break_motor(uint8_t motor);
void _init_dc_control(void);
int16_t _update_controller(uint8_t motor);
int16_t _dc_controller_loop();

#endif /* __DC_CONTROL___H_ */