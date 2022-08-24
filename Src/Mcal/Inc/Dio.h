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

#ifndef DIO_H_
#define DIO_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
 #include "Dio_Lcfg.h"
 #include "common_macros.h"
 
/********************************************************************************
 *                            GLOBAL FUNCTION PROTOTYPES                        *
 ********************************************************************************/
 
 /*********************************************************************************
 * \Syntax           : Dio_ReadChannel                                           *
 * \Description      : Function for Dio to Read Channel API                      *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType                              *
 * \Parameters (out) : Dio_level_Type                                            *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 *********************************************************************************/
Dio_Level_Type Dio_ReadChannel (Dio_ChannelType Channel_ID);

/*********************************************************************************
 * \Syntax           : Dio_WriteChannel                                          *
 * \Description      : Function for Dio to Write Channel API                     *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType, Level - Dio_Level_Type      *
 * \Parameters (out) : None                                                      *
 * \Return value     : void                                                      *
 *                                                                               *
 *********************************************************************************/ 
void Dio_WriteChannel (Dio_ChannelType Channel_ID, Dio_Level_Type Level);

/*********************************************************************************
 * \Syntax           : Dio_FlipChannel                                           *
 * \Description      : Function for Dio to Flip then Read Channel API            *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType                              *
 * \Parameters (out) : Dio_level_Type                                            *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 ********************************************************************************/
Dio_Level_Type Dio_FlipChannel (Dio_ChannelType Channel_ID);

/*********************************************************************************
 * \Syntax           : Dio_ReadPort                                              *
 * \Description      : Function for Dio to Read Port API                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Port_ID - Dio_PortType                                    *
 * \Parameters (out) : Dio_Port_levelType                                        *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 ********************************************************************************/
Dio_Port_LevelType Dio_ReadPort (Port_PortType PortID);

/*********************************************************************************
 * \Syntax           : Dio_ReadPort                                              *
 * \Description      : Function for Dio to Write Port API                        *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Port_ID - Dio_PortType, Level Dio_Port_LevelType          *
 * \Parameters (out) : None                                                      *
 * \Return value     : void                                                      *
 *                                                                               *
 ********************************************************************************/
void Dio_WritePort ( Dio_PortType PortID, Dio_Port_LevelType Level);

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
 #endif /* DIO_H_ */
/********************************************************************************
 *                              END OF FILE : Dio.h                             *
 ********************************************************************************/
 