/*
 * __INT_0_1__.h
 *
 * Created: 5/11/2021 9:18:06 AM
 *  Author: adnan
 */ 


#ifndef __INT_0_1___H_
#define __INT_0_1___H_

#include <__swarm_wold__.h>

#define _INT_LOW_LEVEL 0
#define _INT_CHANGE_LEVEL 1
#define _INT_FALLING_EDGE 2
#define _INT_RISING_EDGE 3


void _interrupt0_enable(uint8_t trigger);
void _interrupt1_enable(uint8_t trigger);




#endif /* __INT_0_1___H_ */