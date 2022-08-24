/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Input.c                                                   *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Input                                                     *
 *                                                                              *
 *      Description : Source file for the Input Module                          *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/


/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "Input.h"

/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTION                                *
 ********************************************************************************/

/********************************************************************************
 * \Syntax           : Get_NumOfPress                                           *
 * \Description      : Function to identify the number of Pluse as input        *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Master_Channel - Service_Channel                         *
 *                     Master_Status - Service_Channel                          *
 *                     Slave_Channel - Service_Channel                          *
 *                     Slave_Status - Service_Channel                           *
 *                     Button_Attach - Button_AttachType                        *
 *                                                                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
uint8 Get_NumOfPress (Service_Channel Master_Channel, Service_Channel Master_Status, Service_Channel Slave_Channel, Service_Channel Slave_Status, Button_AttachType Button_Attach)
{
    uint8 Pulse = 0;

    uint32 i = 0;

    LED_Initialize();

    Button_Initialize;

    while (Get_State(Master_Channel, Button_Attach) == Button_Released);
    
    LED_ON(Master_Status);
    
    for (i = 1250000; i>0; i--);

    LED_OFF(Master_Status);

    while (1)
    {
        if (Get_State(Master_Channel, Button_Attach) == Button_Pressed)
        {
            LED_ON(Master_Status);

            for (i = 1250000; i>0; i--);

            LED_OFF(Master_Status);

            break;
        }

        else if (Get_State(Slave_Channel, Button_Attach) == Button_Pressed)
        {
            LED_ON(Slave_Status);

            for (i = 1250000; i>0; i--);

            LED_OFF(Slave_Status);

            Pulse++;
        }
        
        else
        {
            break;
        } 
    }

    for (i = 1250000; i>0; i--);

    return Pulse;
}


/********************************************************************************
*                                 LOCAL DATA                                    *
 ********************************************************************************/
 
/********************************************************************************
 *                          LOCAL FUNCTION PROTOTYPES                           *
 ********************************************************************************/
 
/********************************************************************************
 *                               LOCAL FUNCTIONS                                *
 ********************************************************************************/

/********************************************************************************
 *                           END OF FILE : Input.c                              *
 ********************************************************************************/