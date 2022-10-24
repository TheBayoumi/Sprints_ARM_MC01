/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Common_Macros.h                                           *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Commonly used Macros                                      *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/
#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/********************************************************************************
 *                                    INCLUDES                                  *
 ********************************************************************************/

/********************************************************************************
 *                          GLOBAL MACROS CONSTANT\FUNCTION                     *
 ********************************************************************************/
/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=((uint32)1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~((uint32)1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=((uint32)1<<BIT))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & ((uint32)1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & ((uint32)1<<BIT)) )

/* Get a certain bit in any register */
#define GET_BIT(REG,BIT) (( REG & (1<<BIT))>>BIT)

/* To access the registers by casting and concatination */
#define ACCESS_REG (BASE,OFFSET) (*((volatile uint32*) (BASE,OFFSET)))

/* Convert Seconds into MicroSeconds */
#define Seconds(time) (time*1000000)

/* Convert Seconds into MillieSeconds */
#define MillieSeconds(time) (time*1000)

/* Assembly instruction to change processor State (Enable Interrupts) */
#define ENABLE_INTERRUPTS __asm(" CPSIE i");

/* Assembly instruction to change processor State (Disable Interrupts) */
#define DISABLE_INTERRUPTS __asm(" CPSID i");


#endif /* COMMON_MACROS_H_ */
/********************************************************************************
 *                            END OF FILE : common_Macros.h                     *
 ********************************************************************************/