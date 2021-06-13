#ifndef __ADC___H_
#define __ADC___H_

//#define __ADC_RES_8_BIT
#define __ADC_RES_10_BIT

#include <__swarm_wold__.h>
/*! \file *********************************************************************
 *
 * \brief Header file for __adc__.c
 *
 * - File:               __adc__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            ADC module driver
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:5/19/2021 9:30:13 AM$
 *****************************************************************************/




/**
       * Initialize the ADC module
       */

void _adc_init(void); 

/**
       * Reads from @param channel 
       */
int _adc_read(uint8_t channel /**< [in]adc channel from PortC. */);

#endif /* __ADC___H_ */