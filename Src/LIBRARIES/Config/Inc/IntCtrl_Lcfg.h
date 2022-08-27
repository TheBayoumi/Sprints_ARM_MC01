/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : IntCtrl_Lcfg.h                                            *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Header file to configure NVIC Module                      *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef INTCTRL_LCFG_H_
#define INTCTRL_LCFG_H_


/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/std_types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/MCAL/Inc/IntCtrl_Types.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 #define Processor_Exceptions_Num               10
 #define Microcontroller_Interrupts_Num         24

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 typedef struct 
 {
    IntCtrl_Exception_ConfigType Exceptions[Processor_Exceptions_Num];
    IntCtrl_Interrupt_ConfigType Interrupts[Microcontroller_Interrupts_Num];
 } IntCtrl_Config_Type;

 extern IntCtrl_Config_Type IntCtrl_Config;
 

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
 

#endif /*INTCTRL_LCFG_H_*/

/********************************************************************************
 *                         END OF FILE : IntCtrl_Lcfg.h                         *
 ********************************************************************************/
 
