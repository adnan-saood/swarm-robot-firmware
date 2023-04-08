/**
\mainpage

\b Swarm \b Bot \b Firmware:

A robot operating system for a swarm-bot. Embedded C firmware for a mobile robot. 8-bit AVR microcontroller. Part of a graduation project.

Built using atmel studio but can be moved to makefile at will.

The firmware for the swarm-bot, it is written in C++ and is compiled using the AVR-GCC compiler.

\image html robot.png "Swarm Bot" width=30%

\section Introduction
A robot operating system for a swarm-bot. Embedded C firmware for a mobile robot. 8-bit AVR microcontroller. Part of a graduation project.

Build using atmel studio but can be moved to makefile at will.

\section Source Files Structure

Each file in this graph has a certain harware utility to it. Files are separated into 4 main categories:

File Structure:
	- \b General:
		- Swarm world file \ref __swarm_wold__.h
		- Pin definitions \ref __pin_map.h
	- \b Control: 
		- Odometry calculations: \ref __odometry__.h
		- PID controller \ref __pid__.h
		- Kinematics \ref __kinematics__.h \ref __kinematics__.c
		- Control loop:
			- \ref __dc_control__.h
			- \ref __dc_control__.c
	- \b Communication: 
		- USART \ref __usart__.h \ref __usart__.c
		- Format \ref __format__.h \n

	- <b>Internal AVR Hardware Interface</b>:
		- ADC \ref __adc__.h \ref __adc__.c
		- PWM \ref __pwm__.h \ref __pwm__.c
		- Timers 
			- Timer 0 (Program Flow): \ref __timer0__.h \ref __timer0__.c
			- Timer 1 (Control Loop): \ref __timer1__.h \ref __timer1__.c
			- Timer 2 (Comminication): \ref __timer2__.h \ref __timer2__.c
		- USART \ref __usart__.h
		- Interrupts 0 and 1 \ref __INT_0_1__.h \ref __INT_0_1__.c


In addition to these files the project is compiled with stdio.h support for printf and scanf functions. This makes it more convinient to debug the code and to communicate with the robot using a terminal emulator. The stdio.h library is not included in the project files but is included in the atmel studio project.
This is advantagious for unfamiliar AVR users to comminicate with the robot using a terminal emulator without having to learn the AVR USART structure.

\image html swarm_world.svg "Files Structure"


Go to files in the tree view in the side bar to see the contents of each fole with dependency graphs and contents.

*/

#include <__swarm_wold__.h>

#include <__kinematics__.h>

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	cli();
	board_init();
	DDRB = 0xFF;
	DDRD = 0b01100010;
	
	struct _theta te;
	struct pos p;
	struct pos_dot _p;
	struct _i_pos _i_p;
	struct _omega w;
	te.left = 0;
	te.right = 0;
	w.wl = 0;
	w.wr = 0;
	uint16_t DT = 100;
	uint32_t t_prev = 0;
	sei();
	while (1)
	{
		_set_speed(MA, 200);
		_set_speed(MB, 200);
		_update_omega(&w);
		_i_p = _omega_to_intertial(&w);
		printf("(%f , ", _i_p.v);
		printf(" %f)\n", _i_p.w);
		_delay_ms(100);
		//_set_speed(MA, 80);
		//while(1)
		//{
		//	printf("+(%d,", (int)(_omega_from_encA()*57.29577));
		//	printf(" %d )\n",(int)( _omega_from_encB()*57.29577));
		//	_delay_ms(100);
		//	if(_ticksA() < 0)
		//	{
		//		break;
		//	}
		//}
	}
	return 0;
}

