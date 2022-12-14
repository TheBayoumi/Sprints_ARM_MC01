/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Service_Types.h                                           *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Service_Types                                             *
 *                                                                              *
 *      Description : Header file for Service types                             *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef SERVICE_TYPES_H_
#define SERVICE_TYPES_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
#include "Gpt.h"
#include "Dio.h"
#include "LED.h"
#include "Button.h"
#include "std_types.h"
 
/********************************************************************************
 *                        LOCAL MACROS CONSTANT\FUNCTION                        *
 ********************************************************************************/
 
/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                             GLOBAL DATA PROTOTYPE                            *
 ********************************************************************************/

typedef LED_ChannelType Service_Channel;

typedef uint16 Service_Time_Type;

typedef uint8 Service_High_Period;

typedef uint8 Service_Low_Period;

typedef Gpt_Channel_Type Service_Timer_Channel;

/********************************************************************************
 *                                GLOBAL FUNCTION                               *
 ********************************************************************************/

/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/

#endif /* SERVICE_TYPES_H_ */
/********************************************************************************
 *                         END OF FILE : Service_Types.h                        *
 ********************************************************************************/
 