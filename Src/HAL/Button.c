/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Button.c                                                  *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Button                                                    *
 *                                                                              *
 *      Description : Source file for the Button                                *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/


/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/HAL/Inc/Button.h"

/********************************************************************************
 *                                GLOBAL FUNCTION                               *
 ********************************************************************************/

/********************************************************************************
 * \Syntax           : Button_Initialize                                        *
 * \Description      : Function to Initialize the used MCAL port                *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : void                                                     *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Button_Initialize (void)
{
    Port_Initalize(&PortConfigType);
}

/********************************************************************************
 * \Syntax           : Get_State                                                *
 * \Description      : Function to get the state of the button                  *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : ButtonChannel - Button_ChannelType                       *
 *                     ButtonAttach - Button_AttachType                         *
 * \Parameters (out) : None                                                     *
 * \Return value     : Button_State                                             *
 *                                                                              *
 ********************************************************************************/
Button_State Get_State (Button_ChannelType ButtonChannel, Button_AttachType ButtonAttach)
{
		
		uint32 i = 0;
		
    Dio_Level_Type Level = Dio_Level_LOW;

    if (ButtonAttach == Pull_UP)
    
        Level = Dio_Level_LOW;
    
    else if (ButtonAttach == Pull_DOWN)
    
        Level = Dio_Level_HIGH;
    
        if (Dio_ReadChannel(ButtonChannel) == Level)
        {
            for (i = 0; i < 2500; i++);

            if (Dio_ReadChannel(ButtonChannel) == Level)
            {
                return Button_Pressed;
            }
            else
            {
                return Button_Released;
            }
        }
    else
        return Button_Released;
   
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
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

 
/********************************************************************************
 *                           END OF FILE : Button.c                             *
 ********************************************************************************/
 