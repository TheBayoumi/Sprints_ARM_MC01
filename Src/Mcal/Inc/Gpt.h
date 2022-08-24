/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Gpt.h                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : General Purpose Timer Module                              *
 *                                                                              *
 *      Description : Header file to configure General Purpose Timer Module     *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef GPT_H_
#define GPT_H_


/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "std_types.h"
#include "mcu_hw.h"
#include "common_macros.h"
#include "Gpt_Types.h"
#include "IntCtrl.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 


/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/


/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
 
 /********************************************************************************
 * \Syntax           : Gpt_Initialize                                           *
 * \Description      : Function to initialize and configure the timer           *
 *                     1- Intializer the hardware timer according to datasheet  *
 *                     2- Disable all interrupts notification                   *
 *                     3- Set operation mode to Period/One-Shot                 *
 *                     4- Start and set all the enable Gpt Preedefined          *
 *                        timers to 0                                           *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : ConfigPTR - Gpt_ChannelConfigType                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Gpt_Initialize ( const Gpt_ChannelConfigType* ConfigPTR);

/********************************************************************************
 * \Syntax           : Gpt_EnableNotify                                         *
 * \Description      : Function to Enable notification when the timer finishes  *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_EnableNotify(Gpt_Channel_Type Gpt_Channel_ID);

/********************************************************************************
 * \Syntax           : Gpt_DisableNotify                                        *
 * \Description      : Function to disable notification of timer                *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_DisableNotify(Gpt_Channel_Type Gpt_Channel_ID);

/********************************************************************************
 * \Syntax           : Gpt_StartTimer                                           *
 * \Description      : Function to start counting the timer                     *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (in)  : Gpt_Value - Gpt_ValueType                                *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_StartTimer (Gpt_Channel_Type Gpt_Channel_ID, Gpt_ValueType Gpt_Value);

/********************************************************************************
 * \Syntax           : Gpt_StopTimer                                            *
 * \Description      : Function to stop counting the timer                      *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type,                       *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_StopTimer (Gpt_Channel_Type Gpt_Channel_ID);

/********************************************************************************
 * \Syntax           : Gpt_GetTimeElapsed                                       *
 * \Description      : Function to get the counted time                         *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : Gpt_ValueType                                            *
 *                                                                              *
 ********************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed (Gpt_Channel_Type Gpt_Channel_ID);

/********************************************************************************
 * \Syntax           : Gpt_GetTimeRemaining                                     *
 * \Description      : Function to get the remaining time                       *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : Gpt_ValueType                                            *
 *                                                                              *
 ********************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining (Gpt_Channel_Type Gpt_Channel_ID);

#endif /*GPT_H_*/

/********************************************************************************
 *                               END OF FILE : Gpt.h                            *
 ********************************************************************************/
 
