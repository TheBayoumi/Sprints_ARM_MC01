/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : mcu_hw.h                                 	                *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : mcu hw                                                    *
 *                                                                              *
 *      Description : Header File for the MC hardware Peripherals               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef MCU_HW_H_
#define MCU_HW_H_

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
	uint32 VECPEND		:8;
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

#define F_CPU									16u

#define CORTEXM4_PERI_BASE_ADDRESS				0xE000E000

#define SysCtrl_BASE_ADDRESS					0x400FE000

/* Application Interrupt and Reset Control */
#define APINT									(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))

/* Interrupt Control and State */
#define INTCTRL									(*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))

/* NVIC Enable */
#define NVIC_EN0 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)))
#define NVIC_EN1 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104)))
#define NVIC_EN2 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108)))
#define NVIC_EN3 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C)))
#define NVIC_EN4 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110)))

/* NVIC Disable */
#define NVIC_DIS0 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180)))
#define NVIC_DIS1 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184)))
#define NVIC_DIS2 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188)))
#define NVIC_DIS3 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C)))
#define NVIC_DIS4 								(*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190)))

/* NVIC Priority */
#define NVIC_PRI_X								0x400

/* System Handler Priority */
#define SYSPRI1 								(*((volatile SYSPRI1_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18)))
#define SYSPRI2 								(*((volatile SYSPRI2_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C)))
#define SYSPRI3 								(*((volatile SYSPRI3_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20)))

/* System Handler Control State */
#define SYSHNDCTRL 								(*((volatile SYSHNDCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)))

/* StytemTick Control and Status Register */
#define STCTRL									(*((volatile SysTickCTRL_BF*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))

/* GPIO Register Base Address */

#define PortA_BASE_ADDRESS						0x40004000
#define PortB_BASE_ADDRESS						0x40005000
#define PortC_BASE_ADDRESS						0x40006000
#define PortD_BASE_ADDRESS						0x40007000
#define PortE_BASE_ADDRESS						0x40024000
#define PortF_BASE_ADDRESS						0x40025000

/* GPIO Registers Offset Address */
#define GPIODATA_OFFSET 						0x3FC
#define GPIODIR_OFFSET 							0x400
#define GPIOAFSEL_OFFSET 						0x420
#define GPIODR2R_OFFSET 						0x500
#define GPIODR4R_OFFSET 						0x504
#define GPIODR8R_OFFSET 						0x508
#define GPIOODR_OFFSET  						0x50C
#define GPIOPUR_OFFSET	 						0x510
#define GPIOPDR_OFFSET	 						0x514
#define GPIOSLR_OFFSET	 						0x518
#define GPIODEN_OFFSET	 						0x51C
#define GPIOLOCK_OFFSET	 						0x520
#define GPIOCR_OFFSET	 						0x524
#define GPIOAMSEL_OFFSET 						0x528
#define GPIOPCTL_OFFSET	 						0x52C

#define PortA_GPIODATA							(*((volatile uint32*)(PortA_BASE_ADDRESS+GPIODATA_OFFSET)))
#define PortB_GPIODATA							(*((volatile uint32*)(PortB_BASE_ADDRESS+GPIODATA_OFFSET)))
#define PortC_GPIODATA							(*((volatile uint32*)(PortC_BASE_ADDRESS+GPIODATA_OFFSET)))
#define PortD_GPIODATA							(*((volatile uint32*)(PortD_BASE_ADDRESS+GPIODATA_OFFSET)))
#define PortE_GPIODATA							(*((volatile uint32*)(PortE_BASE_ADDRESS+GPIODATA_OFFSET)))
#define PortF_GPIODATA							(*((volatile uint32*)(PortF_BASE_ADDRESS+GPIODATA_OFFSET)))

#endif /* MCU_HW_H_ */
/********************************************************************************
 *                              END OF FILE : mcu_hw.h       	                *
 ********************************************************************************/
 