/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Port_Types.h                                              *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Port Types                                                *
 *                                                                              *
 *      Description : Header file for Port Module (Types)                       *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "std_types.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 #define Total_Pin_Num_In_Ports             43u
 #define SysCtrl_RCGCGPIO                   (*((volatile SysCtrl_RCGCGPIO_Tag*)(SysCtrl_BASE_ADDRESS+0x608)))

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
typedef enum
{
    PIN_0 = 0,
    PIN_1 = 1,
    PIN_2 = 2,
    PIN_3 = 3,
    PIN_4 = 4,
    PIN_5 = 5,
    PIN_6 = 6,
    PIN_7 = 7,
} Port_PinType;

typedef enum
{
    PORT_A = 0,
    PORT_B = 1,
    PORT_C = 2,
    PORT_D = 3,
    PORT_E = 4,
    PORT_F = 5
} Port_PortType;

/* Flag for the timer */
typedef enum
{
    Channel_Disable =0,
    Channel_Enable =1
} Port_ChannelMode;

typedef enum
{
    INPUT = 0,
    OUTPUT = 1
} Port_PinDirectionType;

typedef enum
{
    Dio_Mode = 0,
    ICU_Mode = 1,
    ADC_Mode = 2,
} Port_PinModeType;

typedef enum
{
    Pull_UP = 0,
    Pull_DOWN = 1,
    Open_Drain =2,
    Slew_Rate = 3
} Port_PinInternalAttachType;

typedef enum
{
    Current_2mA = 0,
    Current_4mA = 1,
    Current_8mA = 3
} Port_PinOutputCurrentType;

typedef enum
{
    Pin_Level_LOW = 0,
    Pin_Level_HIGH = 1
} Port_PinLevelType;

typedef struct 
{
    uint32 GPIO_PortA                           :1;
    uint32 GPIO_PortB                           :1;
    uint32 GPIO_PortC                           :1;
    uint32 GPIO_PortD                           :1;
    uint32 GPIO_PortE                           :1;
    uint32 GPIO_PortF                           :1;
    uint32                                      :7;
    uint32 UDMA                                 :1;
    uint32                                      :2;
    uint32 USB0                                 :1;
    uint32                                      :15;
} SysCtrl_RCGCGPIO_BF;

typedef union 
{
    uint32 R;
    SysCtrl_RCGCGPIO_BF BF;
} SysCtrl_RCGCGPIO_Tag;

typedef struct 
{
    uint32 L_Byte                               :8;
    uint32                                      :24;
} GPIO_One_Byte_BF;

typedef struct 
{
    Port_PortType Port_Type;
    Port_PinType Pin_Type;
    Port_ChannelMode Is_Enabled;
    Port_PinDirectionType Pin_Direction_Type;
    Port_PinLevelType Pin_Level_Type;
    Port_PinModeType Pin_Mode_Type;
    Port_PinInternalAttachType Pin_InternalAttach_Type;
    Port_PinOutputCurrentType Pin_OutputCurrent_Type;
} Port_Pin_ConfigType;

typedef struct 
{
    Port_Pin_ConfigType PinConfigType[Total_Pin_Num_In_Ports];
} Port_ConfigType;

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
  

#endif /* PORT_TYPES_H_ */
/********************************************************************************
 *                           END OF FILE : Port_Types.h                         *
 ********************************************************************************/