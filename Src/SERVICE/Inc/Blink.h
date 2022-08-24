/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Button.h                                                  *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Button                                                    *
 *                                                                              *
 *      Description : Header file for Button Driver                             *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef BLINK_H_
#define BLINK_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
#include "Gpt.h"
#include "common_macros.h"
#include "Service_Types.h"
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

static Service_Timer_Channel TimerChannel;
static Service_Channel DeviceChannel;
static uint8 Flag = 0;

/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTION                                *
 ********************************************************************************/

/********************************************************************************
 * \Syntax           : Blinking_Start                                           *
 * \Description      : Function to Initialize and Start Blinkning               *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : TimerChannel - Service_Timer_Channel                     *
 *                     DeviceChannel - Service_Channel                          *
 *                     Time - Service_Time_Type                                 *
 *                     HighPeriod - Service_High_Period                         *
 *                     LowPeriod - Service_Low_Period                           *
 *                                                                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Blinking_Start(Service_Timer_Channel TimerChannel, Service_Channel DeviceChannel,Service_Time_Type Time, Service_High_Period HighPeriod,Service_Low_Period LowPeriod);

/********************************************************************************
 * \Syntax           : Blinking_Stop                                            *
 * \Description      : Function to Stop Blinking                                *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : DeviceChannel - Service_Channel                          *
 *                                                                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Blinking_Stop (Service_Channel DeviceChannel);

/********************************************************************************
*                                 LOCAL DATA                                    *
 ********************************************************************************/
 
/********************************************************************************
 *                          LOCAL FUNCTION PROTOTYPES                           *
 ********************************************************************************/
 
/********************************************************************************
 *                               LOCAL FUNCTIONS                                *
 ********************************************************************************/

#endif /* BUTTON_H_ */
/********************************************************************************
 *                           END OF FILE : Blink.h                              *
 ********************************************************************************/ 