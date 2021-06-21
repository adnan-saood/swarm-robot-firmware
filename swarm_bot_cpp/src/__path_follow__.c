#include <__path_follow__.h>

static struct PID_DATA pidLinear;
static struct PID_DATA pidAngular;

void _init_path_control(void)
{
	pid_Init(K_P_L * SCALING_FACTOR, K_I_L * SCALING_FACTOR , K_D_L * SCALING_FACTOR , &pidLinear);
	pid_Init(K_P_T * SCALING_FACTOR, K_I_T * SCALING_FACTOR , K_D_T * SCALING_FACTOR , &pidAngular);
	sei();
}

float _get_controller_u_L(float ref, float sen)
{
	float u;
	u = pid_Controller(ref,sen, &pidLinear);
	return u;
}

float _get_controller_u_A(float ref, float sen)
{
	float u;
	u = pid_Controller(ref,sen, &pidAngular);
	return u;
}