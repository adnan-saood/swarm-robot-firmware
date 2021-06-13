#ifndef __INT_0_1___H_
#define __INT_0_1___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __INT_0_1__.c
 *
 * - File:              __INT_0_1__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            external interrupt driver
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:5/11/2021 9:18:06 AM$
 *****************************************************************************/

#include <__swarm_wold__.h>

#define _INT_LOW_LEVEL 0
#define _INT_CHANGE_LEVEL 1
#define _INT_FALLING_EDGE 2
#define _INT_RISING_EDGE 3

/**
       * Enable interrupt of pin INT0 (see _pin_map.h)
       */
void _interrupt0_enable(uint8_t trigger /**< [in] trigger mode, see file __INT_0_1__.h */);

/**
       * Enable interrupt of pin INT1 (see _pin_map.h)
       */
void _interrupt1_enable(uint8_t trigger/**< [in] trigger mode, see file __INT_0_1__.h */;




#endif /* __INT_0_1___H_ */