# SWARM-Bot fimrware

## Introduction

A robot operating system for a swarm-bot. Embedded C firmware for a mobile robot. 8-bit AVR microcontroller. Part of a graduation project.

Built using atmel studio but can be moved to makefile at will.

**Documentation**
Please follow this url for a gh-pages with full documentation of the sources. You can find file maps and dependency graphs in each class description. [Documentation Site](https://adnan-saood.github.io/swarm-robot-firmware/)


<p align="center">
    <img src="./doc/visuals/robot.png" width=200,>
</p>

## File Structure

<img src="./doc/visuals/swarm_world.svg">


Each file in this graph has a certain harware utility to it. Files are separated into 4 main categories:

### General:
- Swarm world file [`__swarm_world__.h`](./swarm_bot_cpp/src/__swarm_wold__.h)
- Pin definitions [`__pin_map__.h`](./swarm_bot_cpp/src/__pin_map__.h)

### Control:
- Odometry calculations: [`__odometry__.h`](./swarm_bot_cpp/src/__odometry__.h)
- PID controller [`__pid__.h`](./swarm_bot_cpp/src/__pid__.h)
- Kinematics [`__kinematics__.h`](./swarm_bot_cpp/src/__kinematics__.h) [`__kinematics__.c`](./swarm_bot_cpp/src/__kinematics__.c)
- Control loop:
	- [`__dc_control__.h`](./swarm_bot_cpp/src/__dc_control__.h)
	- [`__dc_control__.c`](./swarm_bot_cpp/src/__dc_control__.c)

### Communication:
- USART [`__usart__.h`](./swarm_bot_cpp/src/__usart__.h) [`__usart__.c`](./swarm_bot_cpp/src/__usart__.c)
- Format [`__format__.h`](./swarm_bot_cpp/src/__format__.h)

### Internal AVR Hardware Interface:
- ADC [`__adc__.h`](./swarm_bot_cpp/src/__adc__.h) [`__adc__.c`](./swarm_bot_cpp/src/__adc__.c)
- PWM [`__pwm__.h`](./swarm_bot_cpp/src/__pwm__.h) [`__pwm__.c`](./swarm_bot_cpp/src/__pwm__.c)
- Timers:
	- Timer 0 (Program Flow): [`__timer0__.h`](./swarm_bot_cpp/src/__timer0__.h) [`__timer0__.c`](./swarm_bot_cpp/src/__timer0__.c)
	- Timer 1 (Control Loop): [`__timer1__.h`](./swarm_bot_cpp/src/__timer1__.h) [`__timer1__.c`](./swarm_bot_cpp/src/__timer1__.c)
	- Timer 2 (Communication): [`__timer2__.h`](./swarm_bot_cpp/src/__timer2__.h) [`__timer2__.c`](./swarm_bot_cpp/src/__timer2__.c)
- USART [`__usart__.h`](./swarm_bot_cpp/src/__usart__.h)
- Interrupts 0 and 1 [`__INT_0_1__.h`](./swarm_bot_cpp/src/__INT_0_1__.h) [`__INT_0_1__.c`](./swarm_bot_cpp/src/__INT_0_1__.c)

----

In addition to these files the project is compiled with stdio.h support for printf and scanf functions. This makes it more convinient to debug the code and to communicate with the robot using a terminal emulator. The stdio.h library is not included in the project files but is included in the atmel studio project. This is advantagious for unfamiliar AVR users to comminicate with the robot using a terminal emulator without having to learn the AVR USART structure.
