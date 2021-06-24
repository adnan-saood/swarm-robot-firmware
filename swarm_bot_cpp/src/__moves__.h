


#ifndef __MOVES___H_
#define __MOVES___H_



#include <__swarm_wold__.h>


#define FRWD 1
#define BCKD 2
#define LEFT 3
#define RIGT 4



#define SPEED 100

#define DFT_TICKS 33

#define DFT_TICKS_TURN 14

int64_t _move(int dir);
int64_t _move_forward();
int64_t _move_left();
int64_t _move_right();

#endif /* __MOVES___H_ */