
#ifndef __PATH_FOLLOW___H_
#define __PATH_FOLLOW___H_
#include <__swarm_wold__.h>


#define K_P_L    10.0
#define K_I_L     0.0
#define K_D_L     0.0

#define K_P_T     50.0
#define K_I_T     0.0
#define K_D_T     0.0


void _init_path_control(void);

float _get_controller_u_L(float ref, float sen);

float _get_controller_u_A(float ref, float sen);

#endif /* __PATH_FOLLOW___H_ */