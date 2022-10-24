/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Gpt.c                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Gpt                                                       *
 *                                                                              *
 *      Description : Source file for Genenral Purpose Timer module             *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "Gpt.h"
#include "mcu_hw.h"
#include "IntCtrl.h"
#include "Gpt_Types.h"
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
 * \Syntax           : Gpt_Initialize                                           *
 * \Description      : Function to initialize and configure the timer           *
 *                     1- Intializer the hardware timer according to datasheet  *
 *                     2- Disable all interrupts notification                   *
 *                     3- Set operation mode to Period/One-Shot                 *
 *                     4- Start and set all the enable Gpt Preedefined          *
 *                        timers to 0                                           *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : ConfigPTR - Gpt_ChannelConfigType                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Gpt_Initialize ( const Gpt_ChannelConfigType* ConfigPTR)
{
		uint8 x;
    if (ConfigPTR ->Gpt_IsEnabled == Gpt_Disable)
    {
        return;
    }

    /* Disable all Interrupts to finish initialization */
    DISABLE_INTERRUPTS
		
    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile Gpt_Timer_InterruptType InterruptID = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_0A;
        SysCtrl_RCGCTIMER.R0 = 1;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_1A;
        SysCtrl_RCGCTIMER.R1 = 1;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_2A;
        SysCtrl_RCGCTIMER.R2 = 1;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_3A;
        SysCtrl_RCGCTIMER.R3 = 1;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_4A;
        SysCtrl_RCGCTIMER.R4 = 1;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_5A;
        SysCtrl_RCGCTIMER.R5 = 1;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_0A;
        SysCtrl_RCGCwTIMER.R0 = 1;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_1A;
        SysCtrl_RCGCwTIMER.R1 = 1;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_2A;
        SysCtrl_RCGCwTIMER.R2 = 1;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_3A;
        SysCtrl_RCGCwTIMER.R3 = 1;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_4A;
        SysCtrl_RCGCwTIMER.R4 = 1;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_5A;
        SysCtrl_RCGCwTIMER.R5 = 1;
        break;

    default:
        break;
    }

    /* Enable Interrupt for the selected channel */
    IntCtrl_Enable_Interrupt(InterruptID, ConfigPTR ->Gpt_NotifyPriorty);

    /* Must clear the TAEN before making changes */
    GPTMCTL(ChannelPTR).TAEN = 0;

    /* GPTM Configured for One-Shot/Periodic Modes */
    GPTMCFG(ChannelPTR) = 0x00000000;

    /* Enable GPTM Timer A Match Interrupt */
    GPTMTAMR(ChannelPTR).TAMIE = 1;
		
		/* Enable GPTM Timer A Match Interrupt */
    GPTMTAMR(ChannelPTR).TAMIE = 1;

		/* Chosse GPTM Timer A Mode */
    GPTMTAMR(ChannelPTR).TAMR = ConfigPTR ->Gpt_Mode;
		
    /* Choose GPTM Timer A Count Direction */
    GPTMTAMR(ChannelPTR).TACDIR = ConfigPTR ->Gpt_Direction;

    /* Enable GPTM Timer A Interval Load Write */
    GPTMTAMR(ChannelPTR).TAILD = 1;
    
    /* Enable GPTM Timer A Match Register Update */
    GPTMTAMR(ChannelPTR).TAMRSU = 1;

    /* Enable GPTM Timer A Time-Out Interrupt Mask */
    GPTMIMR(ChannelPTR).TATOIM = 1;

    /* Enable Interrupts */
    ENABLE_INTERRUPTS
}

/********************************************************************************
 * \Syntax           : Gpt_EnableNotify                                         *
 * \Description      : Function to Enable notification when the timer finishes  *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_EnableNotify(Gpt_Channel_Type Gpt_Channel_ID)
{
    Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile Gpt_Timer_InterruptType InterruptID = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_0A;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_1A;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_2A;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_3A;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_4A;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_5A;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_0A;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_1A;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_2A;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_3A;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_4A;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_5A;
        break;

    default:
        break;
    }

    /* Enable GPTM Timer A Time-Out Interrupt Mask */
    GPTMIMR(ChannelPTR).TATOIM = 1;

    /* Enable Interrupt */
    IntCtrl_Enable_Interrupt(InterruptID, ConfigPTR ->Gpt_NotifyPriorty);
}

/********************************************************************************
 * \Syntax           : Gpt_DisableNotify                                        *
 * \Description      : Function to disable notification of timer                *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_DisableNotify(Gpt_Channel_Type Gpt_Channel_ID)
{
    Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile Gpt_Timer_InterruptType InterruptID = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_0A;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_1A;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_2A;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_3A;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_4A;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        InterruptID = BIT_16_32_TIMER_5A;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_0A;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_1A;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_2A;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_3A;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_4A;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        InterruptID = BIT_32_64_TIMER_5A;
        break;

    default:
        break;
    }

    /* Disable GPTM Timer A Time-Out Interrupt Mask */
    GPTMIMR(ChannelPTR).TATOIM = 0;

    /* Disable Interrupts */
    IntCtrl_Disable_Interrupt(InterruptID);

}

/********************************************************************************
 * \Syntax           : Gpt_StartTimer                                           *
 * \Description      : Function to start counting the timer                     *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (in)  : Gpt_Value - Gpt_ValueType                                *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_StartTimer (Gpt_Channel_Type Gpt_Channel_ID, Gpt_ValueType Gpt_Value)
{
    const Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile uint8 Timer_Width = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;
    
    default:
        break;
    }
		
		Gpt_Value = Gpt_Value * F_CPU;
		
    switch (Timer_Width)
    {
    case 32:
        /* Set the count value */
        GPTMTAILR(ChannelPTR) = Gpt_Value & (0x00000000FFFFFFFF);
        break;
    
    case 64:
        /* Set the count value */
        GPTMTBILR(ChannelPTR) = ((Gpt_Value)& (0xFFFFFFFF00000000))>>32;
        
        GPTMTAILR(ChannelPTR) = Gpt_Value & (0x00000000FFFFFFFF);
        break;

    default:
        break;
    }

    /* Enable GPTM Timer A */
    GPTMCTL(ChannelPTR).TAEN = 1;
}

/********************************************************************************
 * \Syntax           : Gpt_StopTimer                                            *
 * \Description      : Function to stop counting the timer                      *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type,                       *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Gpt_StopTimer (Gpt_Channel_Type Gpt_Channel_ID)
{
    Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile uint8 Timer_Width = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        break;
    
    default:
        break;
    }

    /* Disable GPTM Timer A */
    GPTMCTL(ChannelPTR).TAEN = 0;
}

/********************************************************************************
 * \Syntax           : Gpt_GetTimeElapsed                                       *
 * \Description      : Function to get the counted time                         *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : Gpt_ValueType                                            *
 *                                                                              *
 ********************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed (Gpt_Channel_Type Gpt_Channel_ID)
{
    Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile uint8 Timer_Width = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;
    
    default:
        break;
    }

    if (Timer_Width == 32)
    {
        uint32 Elapsed_Time = GPTMTAV (ChannelPTR);

        Elapsed_Time = Elapsed_Time / F_CPU;

        return Elapsed_Time;
    }
    else if (Timer_Width == 64)
    {
        uint64 Elapsed_Time  = ((uint64)GPTMTAV (ChannelPTR) & (0x00000000FFFFFFFF))<<32;

        Elapsed_Time |= GPTMTAV (ChannelPTR) & (0x00000000FFFFFFFF);

        Elapsed_Time = Elapsed_Time / F_CPU;

        return Elapsed_Time;
    }
    return 0;
}

/********************************************************************************
 * \Syntax           : Gpt_GetTimeRemaining                                     *
 * \Description      : Function to get the remaining time                       *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : Gpt_Channel_ID - Gpt_Channel_Type                        *
 * \Parameters (out) : None                                                     *
 * \Return value     : Gpt_ValueType                                            *
 *                                                                              *
 ********************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining (Gpt_Channel_Type Gpt_Channel_ID)
{
    Gpt_ChannelConfigType* ConfigPTR = &(Gpt_Config_Types.GptChannel[Gpt_Channel_ID]);

    volatile uint8 *ChannelPTR = NULL_PTR;

    volatile uint8 Timer_Width = 0;

    switch (ConfigPTR ->Gpt_ChannelID)
    {
    case Timer_0_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_1_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_2_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_3_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;
    
    case Timer_4_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_5_16_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_16Bit_BASE_ADDRESS;
        Timer_Width = 32;
        break;

    case Timer_0_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer0_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_1_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer1_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_2_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer2_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_3_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer3_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_4_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer4_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;

    case Timer_5_32_Bit:
        ChannelPTR = (volatile uint8*)Gpt_Timer5_32Bit_BASE_ADDRESS;
        Timer_Width = 64;
        break;
    
    default:
        break;
    }

    if (Timer_Width == 32)
    {
        uint32 Elapsed_Time = GPTMTAV (ChannelPTR);

        Elapsed_Time = Elapsed_Time / F_CPU;

        
        uint32 Target_Time = GPTMTAILR (ChannelPTR);

        uint32 Remaining_Time = Target_Time - Elapsed_Time;

        return Remaining_Time;
    }

    else if (Timer_Width == 64)
    {
        uint64 Elapsed_Time = ((uint64) GPTMTBV (ChannelPTR) & (0x00000000FFFFFFFF))<<32;

        Elapsed_Time |= GPTMTAV (ChannelPTR) & (0x00000000FFFFFFFF);

        Elapsed_Time = Elapsed_Time /F_CPU;


        uint64 Target_Time = ((uint64) GPTMTAV (ChannelPTR) & (0x00000000FFFFFFFF))<<32;

        Target_Time |= GPTMTAILR (ChannelPTR) & (0x00000000FFFFFFFF);

        uint64 Remaining_Time = Target_Time - Elapsed_Time;

        return Remaining_Time;
    }
    
    return 0;
}

/********************************************************************************
 *                             END OF FILE : Gpt.c                              *
 ********************************************************************************/
 