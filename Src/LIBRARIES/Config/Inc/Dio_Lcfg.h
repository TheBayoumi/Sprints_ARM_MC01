/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : File:  <Write File Name>                                  *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : <Write File DESCRIPTION here>                             *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef DIO_LCFG_H_
#define DIO_LCFG_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "std_types.h"
#include "Dio_Types.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 #define Number_Configured_Channels                 5u

/* Index channel in sort of array of structure */
 #define Dio_Config_LED1_Channel_ID                 (uint8)0x01
 #define Dio_Config_LED2_Channel_ID                 (uint8)0x02
 #define Dio_Config_LED3_Channel_ID                 (uint8)0x03

 #define Dio_Config_SWITCH1_Channel_ID              (uint8)0x00
 #define Dio_Config_SWITCH2_Channel_ID              (uint8)0x04

/* Configurations of Port ID */
 #define Dio_Config_LED1_Port                       (Dio_PortType)PORT_F
 #define Dio_Config_LED2_Port                       (Dio_PortType)PORT_F
 #define Dio_Config_LED3_Port                       (Dio_PortType)PORT_F

 #define Dio_Config_SWITCH1_Port                    (Dio_PortType)PORT_F
 #define Dio_Config_SWITCH2_Port                    (Dio_PortType)PORT_F

/* Configurations of Channel ID */
 #define Dio_Config_LED1_Channel                    (Dio_PinType)PIN_1
 #define Dio_Config_LED2_Channel                    (Dio_PinType)PIN_2
 #define Dio_Config_LED3_Channel                    (Dio_PinType)PIN_3

 #define Dio_Config_SWITCH1_Channel                 (Dio_PinType)PIN_4
 #define Dio_Config_SWITCH2_Channel                 (Dio_PinType)PIN_0


/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 typedef struct 
 {
   Dio_Channel_ConfigType Channels[Number_Configured_Channels];
 } Dio_Config_Types;
 

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/

extern const Dio_Config_Types ConfigTypes;

#endif /* DIO_LCFG_H_ */ 
/********************************************************************************
 *                           END OF FILE : Dio_Lcfg.h                           *
 ********************************************************************************/
 