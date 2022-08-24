/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : LED.c                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : LED                                                       *
 *                                                                              *
 *      Description : Source file for the LED                                   *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/


/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "LED.h"

/********************************************************************************
 *                                GLOBAL FUNCTION                               *
 ********************************************************************************/

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
void LED_Initialize (void)
{
    Port_Initalize(&PortConfigType);
}

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
void LED_ON (LED_ChannelType LED_Channel)
{
    Dio_WriteChannel( LED_Channel, Dio_Level_HIGH);
}

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
void LED_OFF (LED_ChannelType LED_Channel)
{
    Dio_WriteChannel( LED_Channel, Dio_Level_LOW);
}

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
void LED_Toggle (LED_ChannelType LED_Channel)
{
    Dio_FlipChannel( LED_Channel);
}

/********************************************************************************
 *                                 LOCAL DATA                                   *
 ********************************************************************************/
 
/********************************************************************************
 *                                GLOBAL DATA                                   *
 ********************************************************************************/
 
/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                              LOCAL FUNCTIONS                                 *
 ********************************************************************************/

/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

 /********************************************************************************
 *                          END OF FILE : LED.c                                 *
 ********************************************************************************/
 