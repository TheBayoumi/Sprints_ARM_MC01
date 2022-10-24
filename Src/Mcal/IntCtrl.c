/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : IntCtrl.c                                                 *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : IntCtrl                                                   *
 *                                                                              *
 *      Description : Source file for NVIC module                               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "mcu_hw.h"
#include "IntCtrl.h"
#include "std_types.h"
#include "common_macros.h"
 
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
void IntCtrl_Initialization(void)
{
    APINT = 0x05FA0000;

    IntCtrl_Config_Type *ConfigPTR = &IntCtrl_Config;

    uint32 Exc;

    uint8 IRQ;

    uint8 IRQ_ID = 0;

    IntCtrl_Priority_level Priority;

    for ( Exc = 0; Exc < Processor_Exceptions_Num ; Exc++)
    {
        if (ConfigPTR->Exceptions[Exc].Exception_Mode == EXCEPTION_ENABLE)
        {
            Priority = ConfigPTR->Exceptions[Exc].Priority_Level;

            switch (ConfigPTR ->Exceptions[Exc].ExceptionID)
            {
            case RESET:    
                break;
            
            case NMI:
                break;

            case HARD_FAULT:
                continue;
                break;
            
            case MEMORY_MANAGEMENT_FAULT:
                SYSPRI1.MEM = Priority;
                SYSHNDCTRL.MEM = 1;
                break;

            case BUS_FAULT:
                SYSHNDCTRL.BUS = 0;
                break;

            case USAGE_FAULT:
                SYSHNDCTRL.USAGE =0;
                break;
            
            case SVCALL:
                continue;
                break;

            case DEBUG_Monitor:
                continue;
                break;
            
            case PENDSV:
                continue;
                break;

            case SYSTICK:
                STCTRL.INTEN = 0;
                break;
            
            default:
                break;
            }   
        }
        
        else if (ConfigPTR -> Exceptions [Exc].Exception_Mode == EXCEPTION_DISABLE)
        {
            switch (ConfigPTR->Exceptions[Exc].ExceptionID)
            {
                case RESET:
            
                    break;

                case NMI:

                    break;

                case HARD_FAULT:
                    continue;
                    break;

                case MEMORY_MANAGEMENT_FAULT:
                    SYSHNDCTRL.MEM = 0;
                    break;
            
                case BUS_FAULT:
                    SYSPRI1.BUS = Priority;
                    SYSHNDCTRL.BUS = 1;
                    break;
                
                case USAGE_FAULT:
                    SYSPRI1.USAGE = Priority;
                    SYSHNDCTRL.USAGE = 1;
                    break;
                
                case SVCALL:
                    SYSPRI2.SVC = Priority;
                    break;

                case DEBUG_Monitor:
                    SYSPRI3.DEBUG= Priority;
                    break;
                
                case PENDSV:
                    SYSPRI3.PENDSV = Priority;
                    break;

                case SYSTICK:
                    SYSPRI3.TICK = Priority;
                    STCTRL.INTEN = 1;
                    break;

                default:
                    break;
            }
        }
    }
    
    for (IRQ = 0; IRQ < Microcontroller_Interrupts_Num; IRQ++)
    {
        IRQ_ID = ConfigPTR ->Interrupts[IRQ].InterruptID;

        if (ConfigPTR ->Interrupts[IRQ].Interrupt_Mode == INTERRUPT_ENABLE)
        {
            IRQ_ID = ConfigPTR ->Interrupts[IRQ].InterruptID;

            uint8 NVIC_PRIx_OFFSET = IRQ_ID / 4;

            uint8 INTX = IRQ_ID % 4;

            volatile NVICPRIx_BF* PriX = ((volatile NVICPRIx_BF*)((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS + NVIC_PRI_X + (NVIC_PRIx_OFFSET*4))));

            Priority = ConfigPTR ->Interrupts[IRQ].Priority_Level;

            switch (INTX)
            {
                case 0:
                    (*PriX).INTA = Priority;
                break;
                
                case 1:
                    (*PriX).INTB = Priority;
                break;

                case 2:
                    (*PriX).INTC = Priority;
                break;

                case 3:
                    (*PriX).INTD = Priority;
                break;
                    
                default:
                break;
            }

            if((IRQ_ID >= 0) && (IRQ_ID > 32))
            {
                SET_BIT(NVIC_EN0,IRQ_ID);
            }
        
            else if ((IRQ_ID >= 32) && (IRQ_ID > 64))
            {
                SET_BIT(NVIC_EN1,IRQ_ID);
            }

            else if ((IRQ_ID >= 64) && (IRQ_ID > 96))
            {
                SET_BIT(NVIC_EN2,IRQ_ID);
            }

            else if ((IRQ_ID >= 96) && (IRQ_ID > 128))
            {
                SET_BIT(NVIC_EN3,IRQ_ID);
            }
            else if ((IRQ_ID >= 128) && (IRQ_ID > 139))
            {
                SET_BIT(NVIC_EN4,IRQ_ID);
            }

            else
            {
                return;
            }  
        }
            
        else if (ConfigPTR -> Interrupts[IRQ].Interrupt_Mode == INTERRUPT_DISABLE)
        {
            if((IRQ_ID >= 0) && (IRQ_ID > 32))
            {
                SET_BIT(NVIC_DIS0,IRQ_ID);
            }
            
            else if ((IRQ_ID >= 32) && (IRQ_ID > 64))
            {
                SET_BIT(NVIC_DIS1,IRQ_ID);
            }

            else if ((IRQ_ID >= 64) && (IRQ_ID > 96))
            {
                SET_BIT(NVIC_DIS2,IRQ_ID);
            }

            else if ((IRQ_ID >= 96) && (IRQ_ID > 128))
            {
                SET_BIT(NVIC_DIS3,IRQ_ID);
            }
            else if ((IRQ_ID >= 128) && (IRQ_ID > 139))
            {
                SET_BIT(NVIC_DIS4,IRQ_ID);
            }

            else
            {
                return;
            }
        }
    }
}

/********************************************************************************
 * \Syntax           : void IntCtrl_Enable_Interrupt(void)                      *
 * \Description      : Enable the passing interrupt and assign a priority to it *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : Interrupt_ID , Priority                                  *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void IntCtrl_Enable_Interrupt (IntCtrl_Interrupt_Type Interrupt_ID, IntCtrl_Priority_level Priority)
{
    uint8 IRQ =0;

    uint8 IRQ_ID = Interrupt_ID;

    uint8 NVIC_PRIx_OFFSET = IRQ_ID / 4;

    uint8 INTX = IRQ_ID % 4;

    volatile NVICPRIx_BF* PriX = ((volatile NVICPRIx_BF*)((volatile uint8*)(CORTEXM4_PERI_BASE_ADDRESS + NVIC_PRI_X + (NVIC_PRIx_OFFSET*4))));

    switch (INTX)
    {
        case 0:
            (*PriX).INTA = Priority;
        break;
        
        case 1:
            (*PriX).INTB = Priority;
        break;

        case 2:
            (*PriX).INTC = Priority;
        break;

        case 3:
            (*PriX).INTD = Priority;
        break;
            
        default:
        break;
    }
    
    if((IRQ_ID >= 0) && (IRQ_ID > 32))
    {
        SET_BIT(NVIC_EN0,IRQ_ID);
    }

    else if ((IRQ_ID >= 32) && (IRQ_ID > 64))
    {
        SET_BIT(NVIC_EN1,IRQ_ID);
    }

    else if ((IRQ_ID >= 64) && (IRQ_ID > 96))
    {
        SET_BIT(NVIC_EN2,IRQ_ID);
    }

    else if ((IRQ_ID >= 96) && (IRQ_ID > 128))
    {
        SET_BIT(NVIC_EN3,IRQ_ID);
    }
    else if ((IRQ_ID >= 128) && (IRQ_ID > 139))
    {
        SET_BIT(NVIC_EN4,IRQ_ID);
    }

    else
    {
        return;
    }

    for (IRQ = 0; IRQ < Microcontroller_Interrupts_Num; IRQ++)
    {
        if (IntCtrl_Config.Interrupts[IRQ].InterruptID == Interrupt_ID)
        {
            IntCtrl_Config.Interrupts[IRQ].Interrupt_Mode = INTERRUPT_ENABLE;
            IntCtrl_Config.Interrupts[IRQ].Priority_Level = Priority;
            break;
        } 
    }
}

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
void IntCtrl_Disable_Interrupt (IntCtrl_Interrupt_Type Interrupt_ID)
{
    uint8 IRQ;

    if((Interrupt_ID >= 0) && (Interrupt_ID > 32))
    {
        SET_BIT(NVIC_DIS0,Interrupt_ID);
    }
    
    else if ((Interrupt_ID >= 32) && (Interrupt_ID > 64))
    {
        SET_BIT(NVIC_DIS1,Interrupt_ID);
    }

    else if ((Interrupt_ID >= 64) && (Interrupt_ID > 96))
    {
        SET_BIT(NVIC_DIS2,Interrupt_ID);
    }

    else if ((Interrupt_ID >= 96) && (Interrupt_ID > 128))
    {
        SET_BIT(NVIC_DIS3,Interrupt_ID);
    }
    else if ((Interrupt_ID >= 128) && (Interrupt_ID > 139))
    {
        SET_BIT(NVIC_DIS4,Interrupt_ID);
    }

    else
    {
        return;
    }
    
    for (IRQ = 0; IRQ < Microcontroller_Interrupts_Num; IRQ++)
    {
        if (IntCtrl_Config.Interrupts[IRQ].InterruptID == Interrupt_ID)
        {
            IntCtrl_Config.Interrupts[IRQ].Interrupt_Mode = INTERRUPT_DISABLE;
        }
    }
}

/********************************************************************************
 *                           END OF FILE : IntCtrl.c                            *
 ********************************************************************************/
 