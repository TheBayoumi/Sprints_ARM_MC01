/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : mcu_hw.h                                 	                *
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
	uint32 BIT_0 :1;
	uint32 BIT_1 :1;
	uint32 BIT_2 :1;
	uint32 BIT_3 :1;
	uint32 BIT_4 :1;
	uint32 BIT_5 :1;
	uint32 BIT_6 :1;
	uint32 BIT_7 :1;
	uint32 BIT_8 :1;
	uint32 BIT_9 :1;
	uint32 BIT_10 :1;
	uint32 BIT_11 :1;
	uint32 BIT_12 :1;
	uint32 BIT_13 :1;
	uint32 BIT_14 :1;
	uint32 BIT_15 :1;
	uint32 BIT_16 :1;
	uint32 BIT_17 :1;
	uint32 BIT_18 :1;
	uint32 BIT_19 :1;
	uint32 BIT_20 :1;
	uint32 BIT_21 :1;
	uint32 BIT_22 :1;
	uint32 BIT_23 :1;
	uint32 BIT_24 :1;
	uint32 BIT_25 :1;
	uint32 BIT_26 :1;
	uint32 BIT_27 :1;
	uint32 BIT_28 :1;
	uint32 BIT_29 :1;
	uint32 BIT_30 :1;
	uint32 BIT_31 :1;
} BIT_Field;

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

typedef struct
{
	uint32           :5;
	uint32 INTA   	 :3;
	uint32 			 :5;
	uint32 INTB 	 :3;
	uint32    		 :5;
	uint32 INTC 	 :3;
	uint32  		 :5;
	uint32 INTD 	 :3;
} NVICPRIx_BF;

typedef struct
{
	uint32 			:5;
	uint32 MEM		:3;
	uint32 			:5;
	uint32 BUS 		:3;
	uint32 			:5;
	uint32 USAGE 	:3;
	uint32 			:5;
}SYSPRI1_BF; /*System Handler Periorty 1 in BIT Fields*/

typedef struct
{
	uint32 			:29;
	uint32 SVC		:3;
}SYSPRI2_BF; /*System Handler Periorty 2 in BIT Fields*/

typedef struct
{
	uint32 			:5;
	uint32 DEBUG	:3;
	uint32 			:13;
	uint32 PENDSV 	:3;
	uint32  		:5;
	uint32 TICK 	:3;
}SYSPRI3_BF; /*System Handler Periorty 3 in BIT Fields*/

typedef struct 
{
	uint32 MEMA 	:1;
	uint32 BUSA 	:1;
	uint32 			:1;
	uint32 USGA 	:1;
	uint32 			:3;
	uint32 SCVA 	:1;
	uint32 MON 		:1;
	uint32 			:1;
	uint32 PNDSV	:1;
	uint32 TICK 	:1;
	uint32 USAGEP 	:1;
	uint32 MEMP 	:1;
	uint32 BUSP 	:1;
	uint32 SVC 		:1;
	uint32 MEM 		:1;
	uint32 BUS 		:1;
	uint32 USAGE 	:1;
	uint32 			:13;
}SYSHNDCTRL_BF; /*System Handler Control and State in BIT Fields*/

typedef struct 
{
	uint32 ENABLE 	:1;
	uint32 INTEN 	:1;
	uint32 CLK_SRC 	:1;
	uint32 			:13;
	uint32 COUNT 	:1;
	uint32 			:15;
}SysTickCTRL_BF; /*System-Tick Control and Status in BIT Fields*/
 
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

#define NVIC_EN0 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define NVIC_EN1 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define NVIC_EN2 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define NVIC_EN3 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))

#define NVIC_DIS0 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define NVIC_DIS1 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define NVIC_DIS2 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define NVIC_DIS3 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define NVIC_DIS4 								*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

#define NVIC_PRI_X								0X400

#define SYSPRI1 								*((volatile SYSPRI1_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2 								*((volatile SYSPRI2_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3 								*((volatile SYSPRI3_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))

#define SYSHNDCTRL 								*((volatile SYSHNDCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))

#define STCTRL									*((volatile SysTickCTRL_BF)(CORTEXM4_PERI_BASE_ADDRESS+0x010))



#endif /* MCU_HW_H_ */

/********************************************************************************
 *                              END OF FILE : mcu_hw.h       	                *
 ********************************************************************************/
 