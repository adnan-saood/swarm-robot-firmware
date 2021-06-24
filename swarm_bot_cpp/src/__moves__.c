/*
 * __moves__.c
 *
 * Created: 6/22/2021 1:53:31 PM
 *  Author: adnan
 */ 

#include <__moves__.h>

#define DEBUG_MOVES 1

#define W 10
int64_t _move(int dir)
{
	int64_t out;
	switch (dir)
	{
		case FRWD: out =  _move_forward(); break;
//		case BCKD: out =  _move_backward(); break;
		case LEFT: out =  _move_left(); break;
		case RIGT: out =  _move_right(); break;
		default: break;
	}
	
	return out;
}

int64_t _move_forward()
{
	int32_t start_ticksa = _ticksA();
	int32_t start_ticksb = _ticksB();
	uint64_t start_time = _micros0();
	
	_set_speed(MA, SPEED);
	_set_speed(MB, SPEED);
	if(DEBUG_MOVES)
	{
		printf(">>> SET SPEED >>> %d , %d , %ld ||\n",start_ticksa, start_ticksb,start_time );
	}

	while((_ticksA() - start_ticksa) <= DFT_TICKS)
	{
		/*
		 * Proportional Control
		 * Dummy version
		 *
		 */ 
		int ta = (_ticksA() - start_ticksa);
		int e = _ticksA() - _ticksB(); // comment here because it is a shitty solution with very dump starting point...
		_set_speed(MA,SPEED - W*e);
		_set_speed(MB,SPEED + W*e);
	}
	_set_speed(MA,0);
	_set_speed(MB,0);
	return _micros0() - start_time;
}

int64_t _move_left()
{
	printf("start of left\n");
	int32_t start_ticksa = _ticksA();
	int32_t start_ticksb = _ticksB();
	uint64_t start_time = _micros0();
	
	_set_speed(MA,  60);
	_set_speed(MB, -60);
	if(DEBUG_MOVES)
	{
		printf(">>> SET SPEED >>> ||\n");
	}

	while((_ticksB() - start_ticksb) <= DFT_TICKS_TURN)
	{
//		int e = (_ticksA() - start_ticksa) -(_ticksB() - start_ticksb); // comment here because it is a shitty solution with very dump starting point...
//		_set_speed(MA,60 - W*e);
//		_set_speed(MB,-(60 + W*e));
	}
	_set_speed(MA,0);
	_set_speed(MB,0);
	printf("stop speed\n");
	if(DEBUG_MOVES)
	{
		printf("%d\n", (_ticksB() - start_ticksb));
	}
	return _micros0() - start_time;
}

int64_t _move_right()
{
	printf("start of left\n");
	int32_t start_ticksa = _ticksA();
	int32_t start_ticksb = _ticksB();
	uint64_t start_time = _micros0();
	
	_set_speed(MA, -60);
	_set_speed(MB, 60);
	if(DEBUG_MOVES)
	{
		printf(">>> SET SPEED >>> ||\n");
	}

	while((_ticksB() - start_ticksb) <= DFT_TICKS_TURN)
	{
		//		int e = (_ticksA() - start_ticksa) -(_ticksB() - start_ticksb); // comment here because it is a shitty solution with very dump starting point...
		//		_set_speed(MA,60 - W*e);
		//		_set_speed(MB,-(60 + W*e));
	}
	_set_speed(MA,0);
	_set_speed(MB,0);
	printf("stop speed\n");
	if(DEBUG_MOVES)
	{
		printf("%d\n", (_ticksB() - start_ticksb));
	}
	return _micros0() - start_time;
}