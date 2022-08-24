/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : LED.h                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : LED                                                       *
 *                                                                              *
 *      Description : Header file for LED Driver                                *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
#include "std_types.h"
#include "Port.h"
#include "Dio.h"
 
/********************************************************************************
 *                        LOCAL MACROS CONSTANT\FUNCTION                        *
 ********************************************************************************/
 
/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

/********************************************************************************
 *                           GLOBAL FUNCTION PROTOTYPES                         *
 ********************************************************************************/

typedef Dio_ChannelType LED_ChannelType;


/********************************************************************************
 * \Syntax           : LED_Initialize                                           *
 * \Description      : Function to Initialize the led port using MCAL port      *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : void                                                     *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/  
void LED_Initialize (void);

/********************************************************************************
 * \Syntax           : LED_ON                                                   *
 * \Description      : Function to turn on the led the using MCAL port          *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : LED_Channel - LED_ChannelType                            *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void LED_ON (LED_ChannelType LED_Channel);

/********************************************************************************
 * \Syntax           : LED_OFF                                                  *
 * \Description      : Function to turn off the led the using MCAL port         *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : LED_Channel - LED_ChannelType                            *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void LED_OFF (LED_ChannelType LED_Channel);

/********************************************************************************
 * \Syntax           : LED_Toggle                                               *
 * \Description      : Function to toggle the led the using MCAL port           *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : LED_Channel - LED_ChannelType                            *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void LED_Toggle (LED_ChannelType LED_Channel);

/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/

#endif /* LED_H_ */
/********************************************************************************
 *                             END OF FILE : LED.h                              *
 ********************************************************************************/
 