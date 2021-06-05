/*
 * __kinematics__.h
 *
 * Created: 5/29/2021 8:04:54 PM
 *  Author: adnan
 */ 


#ifndef __KINEMATICS___H_
#define __KINEMATICS___H_

#define L 0.06
#define r 0.02
#define R_over_L 0.333
#define R_over_2 0.01


#include <__swarm_wold__.h>

struct point
{
	float x;
	float y;
};

struct pos
{
	float x;
	float y;
	float th;
};

struct pos_dot
{
	float x_dot;
	float y_dot;
	float th_dot;	
};

struct _i_pos
{
	float v;
	float w;	
};

struct mat2
{
	float a;
	float b;
	float c;
	float d;
};

struct _omega
{
	float wl;
	float wr;
};

struct _theta
{
	float left;
	float right;	
};


struct _i_pos _omega_to_intertial(struct _omega * input);

struct pos_dot _inertial_to_pos_dot(struct _i_pos * inertial, struct pos * _pos);

uint16_t _dead_reckon(struct pos * _pos, struct pos_dot * _pos_dot); // uint8_t for debugging

struct pos _thetaLR_to_pos(struct _theta * th);

void _update_thetaLR(struct _theta * input);

void _update_omega(struct _omega * input);

#endif /* __KINEMATICS___H_ */