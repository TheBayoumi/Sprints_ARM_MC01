/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : mcu_hw.h                                               *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Provision of Standard Types                               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef MCU_HW_H
#define MCU_HW_H

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/
 
#include "std_types.h"
 
/********************************************************************************
 *                        LOCAL MACROS CONSTANT\FUNCTION                        *
 ********************************************************************************/
 
/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

typedef struct
{
	uint32 VECACT		:8;
	uint32 				:3;
	uint32 RETBASE		:1;
	uint32 VECPEND		:3;
	uint32 VECPEND		:4;
	uint32 				:2;
	uint32 ISRPEND		:1;
	uint32 ISRPRE		:1;
	uint32				:1;
	uint32 PENDSTCLR	:1;
	uint32 PENDSTSET	:1;
	uint32 UNPENDSV		:1;
	uint32 PENDSV		:1;
	uint32				:2;
	uint32 NMISET		:1;
}INTCTRL_BF;

typedef union
{
	uint32 R;
	INTCTRL_BF B;
}INTCTRL_Tag;

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                             GLOBAL CONSTANT MACROS     	                    *
 ********************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS				0xE000E000
#define APINT									*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL									*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))


#endif /* MCU_HW_H_ */

/********************************************************************************
 *                              END OF FILE : mcu_hw.h       	                *
 ********************************************************************************/
 