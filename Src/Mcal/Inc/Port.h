/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Dio.h                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Dio                                                       *
 *                                                                              *
 *      Description : Header file for Dio module                                *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "std_types.h" 
#include "Port_Lcfg.h"
#include "Port_Types.h"

/********************************************************************************
 *                            GLOBAL FUNCTION PROTOTYPES                        *
 ********************************************************************************/
 
/********************************************************************************
 * \Syntax           : Port_Initialize                                          *
 * \Description      : Function to Setup the Port Configuration                 *
 *                     1- Setup Pin as Digital Gpio Pin                         *
 *                     2- Setup the direction of GPIO Pins                      *
 *                     3- Set Initial Values for the Gpio Pin                   *
 *                     4- Setup the mode of the Gpio Pin                        *
 *                     5- setup the internal Resistor for I/O Pins              *
 *                     6- Setup the output current in case of Output Pin        *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : ConfigPTR - Port_ConfigType                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : Void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Port_Initalize(const Port_ConfigType *ConfigPTR);

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
 * \Syntax           : std_ReturnType FunctionName(AnyType parameterName)       *
 * \Description      : Describe this service                                    *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : parameterName   Parameter Description                    *
 * \Parameters (out) : None                                                     *
 * \Return value     : std_ReturnType  E_OK                                     *
 *                                     E_NOT_OK                                 *
 ********************************************************************************/
 #endif /* PORT_H_ */
/********************************************************************************
 *                              END OF FILE : Port.h                            *
 ********************************************************************************/
 