
#include <stdio.h>
#include <asf.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <__adc__.h>
#include "__usart__.h"
#include "__timer1__.h"
#include <__odometry__.h>

#define K_P     2.0
#define K_I     0.50
#define K_D     0.50


	


#include <_pid_.h>

#define F_CPU 1000000



//! Parameters for regulator
struct PID_DATA pidData;



#include <util/delay.h>


int16_t ref(void)
{
  return 25;
}

/*! \brief Read system process value
 *
 * This function must return the measured data
 */
float sens(void)
{
  return (_omega_from_encA()*9.55);
}

void command(int16_t inputValue)
{
	_set_speed(MA,inputValue);
}



int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	pid_Init(K_P * SCALING_FACTOR, K_I * SCALING_FACTOR , K_D * SCALING_FACTOR , &pidData);
	int16_t referenceValue, measurementValue, inputValue;
	sei();
	
	DDRB = 0xFF;
	DDRD = 0b11101011;
	while (1)
	{
		if(flag)
		{
			referenceValue = ref();
			measurementValue = (int16_t)sens();

			inputValue = pid_Controller(referenceValue, measurementValue, &pidData);

			command(inputValue);
			
			printf("%d - %d\n",measurementValue, inputValue);

			flag = FALSE;
		}
		
	}
	return 0;
}





