/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Input.h                                                   *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Input                                                     *
 *                                                                              *
 *      Description : Header file for input Service                             *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef INPUT_H_
#define INPUT_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/SERVICE/Inc/Service_Types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/HAL/Inc/Button.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/HAL/Inc/LED.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/common_macros.h"
 
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
uint8 Get_NumOfPress (Service_Channel Master_Channel, Service_Channel Master_Status, Service_Channel Slave_Channel, Service_Channel Slave_Status, Button_AttachType Button_Attach);

/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/

#endif /* INPUT_H_ */
/********************************************************************************
 *                             END OF FILE : Input.h                            *
 ********************************************************************************/
 