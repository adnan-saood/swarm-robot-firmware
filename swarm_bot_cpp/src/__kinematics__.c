/*
 * __kinematics__.c
 *
 * Created: 5/29/2021 11:35:20 PM
 *  Author: adnan
 */ 

#include <__kinematics__.h>


void _update_omega(struct _omega * input)
{
	input->wl = _omega_from_encA();
	input->wr = _omega_from_encB();
}

struct _i_pos _omega_to_intertial(struct _omega * input)
{
	float wl = input->wl;
	float wr = input->wr;
	
	struct _i_pos out;
	out.v = (wl+wr)*R_over_2;
	out.w = (wr-wl)*R_over_L;
	return out;
}

struct pos_dot _inertial_to_pos_dot(struct _i_pos * inertial, struct pos * _pos)
{
	float v = inertial->v;
	float w = inertial->w;
	float th = _pos->th;
	struct pos_dot out;
	
	out.x_dot = v * cos(th);
	out.y_dot = v * sin(th);
	out.th_dot = w;
	
	return out;
}

uint16_t _dead_reckon(struct pos * _pos, struct pos_dot * _pos_dot)
{
	static uint64_t t_prev = 0;
	uint32_t dt = _micros0() - t_prev;
	t_prev = _micros0();

	
	_pos->x += _pos_dot->x_dot * dt / 1000000.0;
	_pos->y += _pos_dot->y_dot * dt / 1000000.0;
	_pos->th += _pos_dot->th_dot * dt / 1000000.0;

	return dt;
}

struct pos _thetaLR_to_pos(struct _theta * th)
{
	struct pos out;
	
	out.th = (th->right - th->left)*R_over_L;
	out.x = (th->right + th->left)*R_over_2*cos(out.th);
	out.y = (th->right + th->left)*R_over_2*sin(out.th);
	
	return out;
}

void _update_thetaLR(struct _theta * input)
{
	input->left = _thetaA();
	input->right = -1.0 * _thetaB();
}

