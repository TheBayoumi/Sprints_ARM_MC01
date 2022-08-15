/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Common_Macros.h                                           *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Commonly used Macros                                      *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

/********************************************************************************
 *                                    INCLUDES                                  *
 ********************************************************************************/

#include "std_types.h"

/********************************************************************************
 *                          GLOBAL MACROS CONSTANT\FUNCTION                     *
 ********************************************************************************/


/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=((uint32)1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~((uint32)1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=((uint32)1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & ((uint32)1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & ((uint32)1<<BIT)) )

/* Get a certain bit in any register */
#define GET_BIT (REG,BIT) ((REG>>BIT)&(0x01u))

#endif

/********************************************************************************
 *                              END OF FILE : common_Macros.h                   *
 ********************************************************************************/