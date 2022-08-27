/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : IntCtrl_Tyoes.h                                           *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : IntCtrl                                                   *
 *                                                                              *
 *      Description : Header file for NVIC module                               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef INTCTRL_TYPES_H_
#define INTCTRL_TYPES_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/std_types.h"
#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/mcu_hw.h"
 
/********************************************************************************
 *                             GLOBAL DATA STRUCTURE                            *
 ********************************************************************************/

typedef uint8 IntCtrl_Priority_level;

/* typedef enum
{
    RESET = 0, 
    NMI = 1,
    HARD_FAULT = 2,
    MEMORY_MANAGEMENT_FAULT = 3,
    BUS_FAULT = 4,
    USAGE_FAULT = 5,
    SVCALL = 6,
    DEBUG = 7,
    PENDSV = 8,
    SYSTICK = 9
} IntCtrl_Exception_Type; */

typedef enum
{
    RESET = 1, /* Reset should start by 1 and increment as the vector number does */
    NMI = 2,
    HARD_FAULT = 3,
    MEMORY_MANAGEMENT_FAULT = 4,
    BUS_FAULT = 5,
    USAGE_FAULT = 6,
    SVCALL = 11,
    DEBUG_Monitor = 12,
    PENDSV = 14,
    SYSTICK = 15
} IntCtrl_Exception_Type;

typedef enum
{
    /*  (16 - 32)-Bit Timers  */
    BIT_16_32_TIMER_0A = 19,
    BIT_16_32_TIMER_0B = 20,
    
    BIT_16_32_TIMER_1A = 21,
    BIT_16_32_TIMER_1B = 22,
    
    BIT_16_32_TIMER_2A = 23,
    BIT_16_32_TIMER_2B = 24,
    
    BIT_16_32_TIMER_3A = 35,
    BIT_16_32_TIMER_3B = 36,
    
    BIT_16_32_TIMER_4A = 70,
    BIT_16_32_TIMER_4B = 71,
    
    BIT_16_32_TIMER_5A = 92,
    BIT_16_32_TIMER_5B = 93,

    
    /*  (32 - 64)-Bit Timers  */
    BIT_32_64_TIMER_0A = 94,
    BIT_32_64_TIMER_0B = 95,
    
    BIT_32_64_TIMER_1A = 96,
    BIT_32_64_TIMER_1B = 97,

    BIT_32_64_TIMER_2A = 98,
    BIT_32_64_TIMER_2B = 99,

    BIT_32_64_TIMER_3A = 100,
    BIT_32_64_TIMER_3B = 101,

    BIT_32_64_TIMER_4A = 102,
    BIT_32_64_TIMER_4B = 103,

    BIT_32_64_TIMER_5A = 104,
    BIT_32_64_TIMER_5B = 105
} IntCtrl_Interrupt_Type;

typedef enum
{
    EXCEPTION_DISABLE = 0,
    EXCEPTION_ENABLE = 1
} IntCtrl_Exception_Mode;

typedef enum 
{
    INTERRUPT_DISABLE = 0,
    INTERRUPT_ENABLE = 1
} IntCtrl_Interrupt_Mode;

typedef struct
{
    IntCtrl_Exception_Type ExceptionID;
    IntCtrl_Exception_Mode Exception_Mode;
    IntCtrl_Priority_level Priority_Level;
} IntCtrl_Exception_ConfigType;

typedef struct
{
    IntCtrl_Interrupt_Type InterruptID;
    IntCtrl_Interrupt_Mode Interrupt_Mode;
    IntCtrl_Priority_level Priority_Level;
} IntCtrl_Interrupt_ConfigType;

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



 #endif  /*  INTCTRL_TYPES_H_  */
/********************************************************************************
 *                        END OF FILE : IntCtrl_types.h                         *
 ********************************************************************************/
 