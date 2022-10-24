/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : IntCtrl.h                                                 *
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

#ifndef INTCTRL_H_
#define INTCTRL_H_

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
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
 * \Syntax           : void IntCtrl_Initialization(void)                        *
 * \Description      : Initialize NVIC Module by configuration NVIC registers   *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : None                                                     *
 * \Parameters (out) : None                                                     *
 * \Return value     : Void                                                     *
 *                                                                              *
 ********************************************************************************/
void IntCtrl_Initialization(void);

/********************************************************************************
 * \Syntax           : void IntCtrl_Enable_Interrupt(IntCtrl_Interrupt_Type     *
 *                     Interrupt_ID, IntCtrl_Priority_level Priority)           *
 * \Description      : Enable the passing interrupt and assign a priority to it *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : Interrupt_ID , Priority                                  *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void IntCtrl_Enable_Interrupt (IntCtrl_Interrupt_Type Interrupt_ID, IntCtrl_Priority_level Priority);

/********************************************************************************
 * \Syntax           : void IntCtrl_Disable_Interrupt(void)                     *
 * \Description      : Disable the passing interrupt                            *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : Interrupt_ID ,                                           *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void IntCtrl_Disable_Interrupt (IntCtrl_Interrupt_Type Interrupt_ID);
 
 #endif /* INTCTRL_H_ */

/********************************************************************************
 *                           END OF FILE : IntCtrl.h                            *
 ********************************************************************************/
 