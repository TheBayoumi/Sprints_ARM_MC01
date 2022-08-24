/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Dio_Types.h                                               *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Dio Types                                                 *
 *                                                                              *
 *      Description : Header File for Dio Modules types                         *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
 #include "std_types.h"
 #include "mcu_hw.h"
 #include "Port_Types.h"

/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 #define Port_A_GPIODATA            (*((volatile uint32*)(PortA_BASE_ADDRESS+GPIODATA_OFFSET)))
 #define Port_B_GPIODATA            (*((volatile uint32*)(PortB_BASE_ADDRESS+GPIODATA_OFFSET)))
 #define Port_C_GPIODATA            (*((volatile uint32*)(PortC_BASE_ADDRESS+GPIODATA_OFFSET)))
 #define Port_D_GPIODATA            (*((volatile uint32*)(PortD_BASE_ADDRESS+GPIODATA_OFFSET)))
 #define Port_E_GPIODATA            (*((volatile uint32*)(PortE_BASE_ADDRESS+GPIODATA_OFFSET)))
 #define Port_F_GPIODATA            (*((volatile uint32*)(PortF_BASE_ADDRESS+GPIODATA_OFFSET)))

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 typedef uint8 Dio_ChannelType;

 typedef Port_PinType Dio_PinType;

 typedef Port_PortType Dio_PortType;

 typedef struct 
 {
    Dio_PortType Port_ID;
    Dio_PinType Pin_ID;
 } Dio_Channel_ConfigType;
 
 typedef enum 
 {
    Dio_Level_ERROR = -1,
    Dio_Level_LOW = -0,
    Dio_Level_HIGH = 1
 } Dio_Level_Type;

 typedef uint8 Dio_Port_LevelType; 

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
 
 
#endif /* DIO_TYPES_H_ */
/********************************************************************************
 *                           END OF FILE : Dio_Types.h                          *
 ********************************************************************************/
 