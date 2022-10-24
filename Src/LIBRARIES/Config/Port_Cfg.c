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


/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/

#include "std_types.h"
#include "Port_Types.h" 
 
/********************************************************************************
 *                        LOCAL MACROS CONSTANT\FUNCTION                        *
 ********************************************************************************/
 
/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 const Port_ConfigType PortConfigType ={
  /************************************ Port A ****************************************/
  PORT_A, PIN_0, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_1, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_2, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_3, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_4, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_5, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_6, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_A, PIN_7, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,

  /************************************ Port B ****************************************/
  PORT_B, PIN_0, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_1, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_2, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_3, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_4, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_5, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_6, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_B, PIN_7, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,

  /************************************ Port C ****************************************/
  PORT_C, PIN_0, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,   /* Reserved for JTAG/SWD */
  PORT_C, PIN_1, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,   /* Reserved for JTAG/SWD */
  PORT_C, PIN_2, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,   /* Reserved for JTAG/SWD */
  PORT_C, PIN_3, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,   /* Reserved for JTAG/SWD */
  PORT_C, PIN_4, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_C, PIN_5, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_C, PIN_6, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_C, PIN_7, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,

  /************************************ Port D ****************************************/
  PORT_D, PIN_0, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_1, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_2, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_3, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_4, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_5, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_6, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_D, PIN_7, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,

  /************************************ Port E ****************************************/
  PORT_E, PIN_0, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_E, PIN_1, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_E, PIN_2, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_E, PIN_3, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_E, PIN_4, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,
  PORT_E, PIN_5, Channel_Disable, INPUT, Pin_Level_LOW, Dio_Mode, Pull_UP, Current_2mA,

  /************************************ Port F ****************************************/
  PORT_F, PIN_0, Channel_Enable, INPUT, Pin_Level_HIGH, Dio_Mode, Pull_UP, Current_2mA,
  PORT_F, PIN_1, Channel_Enable, OUTPUT, Pin_Level_LOW, Dio_Mode, Pull_DOWN, Current_2mA,
  PORT_F, PIN_2, Channel_Enable, OUTPUT, Pin_Level_LOW, Dio_Mode, Pull_DOWN, Current_2mA,
  PORT_F, PIN_3, Channel_Enable, OUTPUT, Pin_Level_LOW, Dio_Mode, Pull_DOWN, Current_2mA,
  PORT_F, PIN_4, Channel_Enable, INPUT, Pin_Level_HIGH, Dio_Mode, Pull_UP, Current_2mA,
 };

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
 *                           END OF FILE : Port_cfg.c                           *
 ********************************************************************************/
 