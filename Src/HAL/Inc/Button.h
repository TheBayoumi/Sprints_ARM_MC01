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

#ifndef BUTTON_H_
#define BUTTON_H_

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
 *                             GLOBAL DATA PROTOTYPE                            *
 ********************************************************************************/



/********************************************************************************
 *                                GLOBAL FUNCTION                               *
 ********************************************************************************/

typedef Dio_ChannelType Button_ChannelType;

typedef Port_PinInternalAttachType Button_AttachType;

typedef enum
{
    Button_Released = 0,
    Button_Pressed = 1
} Button_State;

/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 * \Syntax           : Button_Initialize                                        *
 * \Description      : Function to Initialize the button using MCAL port        *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : void                                                     *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Button_Initialize (void);

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
Button_State Get_State (Button_ChannelType ButtonChannel, Button_AttachType ButtonAttach);


#endif /* BUTTON_H_ */
/********************************************************************************
 *                             END OF FILE : Button.h                           *
 ********************************************************************************/
 