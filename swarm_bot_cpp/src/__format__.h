#ifndef __FORMAT___H_
#define __FORMAT___H_

/*! \file *********************************************************************
 *
 * \brief Header file for __format__.c
 *
 * - File:               __format__.h
 * - Compiler:           GCC-AVR
 * - Supported devices:  Tested on 328p
 * - AppNote:            string formatter
 *
 * \author               Swarm robot graduation project workgroub \n
 *						 Mechatronics Program for the Distinguished \n
 *
 * $Name$
 * $Revision: 1 $
 * $RCSfile$
 * $Date:6/5/2021 12:34:35 AM$
 *****************************************************************************/

#include <__swarm_wold__.h>

/**
       * Convert a float varialbe to string
       */
char * _float_to_printable(float input /**< [in]input value of float to convert to string */);

char * _read_path_segment();
#endif /* __FORMAT___H_ */