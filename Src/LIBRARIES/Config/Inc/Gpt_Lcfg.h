/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Gpt_Lcfg.h                                                *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Gpt_Lcfg                                                  *
 *                                                                              *
 *      Description : Header file to configure General Purpose Timer Module     *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef GPT_LCFG_H_
#define GPT_LCFG_H_


/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/MCAL/Inc/Dio.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/std_types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/MCAL/Inc/Gpt_Types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/common_macros.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
#define Gpt_PreDeff_Timer_1US_16Bit            0u
#define Gpt_PreDeff_Timer_1US_24Bit            0u
#define Gpt_PreDeff_Timer_1US_32Bit            0u
#define Gpt_PreDeff_Timer_100US_16Bit          0u

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

extern Gpt_ConfigType Gpt_Config_Types;

extern uint32 Timer_0_Counter;

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
 

#endif /*GPT_LCFG_H_*/

/********************************************************************************
 *                            END OF FILE : Gpt_Lcfg.h                          *
 ********************************************************************************/
 
