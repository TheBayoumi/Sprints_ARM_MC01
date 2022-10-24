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
#include "IntCtrl_Lcfg.h" 
 
/********************************************************************************
 *                        LOCAL MACROS CONSTANT\FUNCTION                        *
 ********************************************************************************/
 
/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 IntCtrl_Config_Type IntCtrl_Config ={
                 /**Exceptions**/ 
    RESET                       , EXCEPTION_ENABLE , -3,
    NMI                         , EXCEPTION_ENABLE , -2,
    HARD_FAULT                  , EXCEPTION_ENABLE , -1,
    MEMORY_MANAGEMENT_FAULT     , EXCEPTION_ENABLE , 0,
    BUS_FAULT                   , EXCEPTION_ENABLE , 0,
    USAGE_FAULT                 , EXCEPTION_ENABLE , 0,
    SVCALL                      , EXCEPTION_ENABLE , 5,
    DEBUG_Monitor               , EXCEPTION_ENABLE , 1,
    PENDSV                      , EXCEPTION_ENABLE , 5,
    SYSTICK                     , EXCEPTION_ENABLE , 5,

                       /**IRQ**/
    BIT_16_32_TIMER_0A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_0B          , INTERRUPT_DISABLE , 0,

    BIT_16_32_TIMER_1A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_1B          , INTERRUPT_DISABLE , 0,
    
    BIT_16_32_TIMER_2A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_2B          , INTERRUPT_DISABLE , 0,
    
    BIT_16_32_TIMER_3A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_3B          , INTERRUPT_DISABLE , 0,

    BIT_16_32_TIMER_4A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_4B          , INTERRUPT_DISABLE , 0,

    BIT_16_32_TIMER_5A          , INTERRUPT_DISABLE , 0,
    BIT_16_32_TIMER_5B          , INTERRUPT_DISABLE , 0,

                    /**32-Bit Timer**/
    BIT_32_64_TIMER_0A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_0B          , INTERRUPT_DISABLE , 0,

    BIT_32_64_TIMER_1A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_1B          , INTERRUPT_DISABLE , 0,

    BIT_32_64_TIMER_2A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_2B          , INTERRUPT_DISABLE , 0,

    BIT_32_64_TIMER_3A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_3B          , INTERRUPT_DISABLE , 0,

    BIT_32_64_TIMER_4A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_4B          , INTERRUPT_DISABLE , 0,

    BIT_32_64_TIMER_5A          , INTERRUPT_DISABLE , 0,
    BIT_32_64_TIMER_5B          , INTERRUPT_DISABLE , 0
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
 *                        END OF FILE : IntCtrl_cfg.c                           *
 ********************************************************************************/
 