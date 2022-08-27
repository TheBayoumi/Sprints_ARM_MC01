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
 
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/std_types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/MCAL/Inc/Gpt.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/MCAL/Inc/Dio.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/HAL/Inc/LED.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/HAL/Inc/Button.h"
 
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
 