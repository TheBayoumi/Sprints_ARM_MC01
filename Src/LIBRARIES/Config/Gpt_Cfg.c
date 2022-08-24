/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Gpt_Cfg.c                                                 *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Gpt_Cfg                                                   *
 *                                                                              *
 *      Description : Source file for Gpt module configurations                 *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 *                                    INCLUDES                                  *
 ********************************************************************************/
 
#include "Gpt_Lcfg.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 void Gpt_Noftification_0  (void);
 void Gpt_Noftification_1  (void);
 void Gpt_Noftification_2  (void);
 void Gpt_Noftification_3  (void);
 void Gpt_Noftification_4  (void);
 void Gpt_Noftification_5  (void);
 void Gpt_Noftification_6  (void);
 void Gpt_Noftification_7  (void);
 void Gpt_Noftification_8  (void);
 void Gpt_Noftification_9  (void);
 void Gpt_Noftification_10 (void);
 void Gpt_Noftification_11 (void);

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/
 
 Gpt_ConfigType Gpt_Config_Type =
 {
    Timer_0_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_0,0,
    Timer_1_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_1,0,
    Timer_2_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_2,0,
    Timer_3_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_3,0,
    Timer_4_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_4,0,
    Timer_5_16_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_5,0,
    Timer_0_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_6,0,
    Timer_1_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_7,0,
    Timer_2_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_8,0,
    Timer_3_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_9,0,
    Timer_4_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_10,0,
    Timer_5_32_Bit, Gpt_Disable, Up, 16000000, Gpt_Channel_Continous_Mode, Gpt_Noftification_11,0

 };

uint32 Timer_0_Counter = 0;

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_0                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_0 (void)
{
    Dio_FlipChannel (Dio_Config_LED1_Channel_ID);   

    Timer_0_Counter++;
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_1                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_1 (void)
{
    Dio_FlipChannel (Dio_Config_LED2_Channel_ID);

    Timer_0_Counter++;
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_2                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_2 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_3                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_3 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_4                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_4 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_5                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_5 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_6                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_6 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_7                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_7 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_8                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_8 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_9                                       *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_9 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_10                                      *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_10 (void)
{
    /* Do Something */
}

/*********************************************************************************
 * \Syntax           : Gpt_Noftification_11                                      *
 * \Description      : CallBack Notification is configurable as pointer to user  *
 *                     defined functions                                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : void                                                      *
 * \Parameters (out) : void                                                      *
 * \Return value     : -                                                         *
 *                                                                               *
 ********************************************************************************/
void Gpt_Noftification_11 (void)
{
    /* Do Something */
}

void Timer_0A_Handler ()
{
    GPTMICR (Gpt_Timer0_16Bit_BASE_ADDRESS).TATOCINT = 1;

    if (Gpt_Config_Type.GptChannel[0].Gpt_Notify != NULL_PTR)
    {
        Gpt_Config_Type.GptChannel[0].Gpt_Notify();
    }
    

}

void Timer_1A_Handler ()
{
    GPTMICR (Gpt_Timer1_16Bit_BASE_ADDRESS).TATOCINT = 1;

    if (Gpt_Config_Type.GptChannel[0].Gpt_Notify != NULL_PTR)
    {
        Gpt_Config_Type.GptChannel[0].Gpt_Notify();
    }
}

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/
 
/********************************************************************************
 * \Syntax           : std_ReturnType FunctionName(AnyType parameterName)       *
 * \Description      : Describe this service                                    *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Non Reentrant                                            *
 * \Parameters (in)  : parameterName   Parameter Description                    *
 * \Parameters (out) : None                                                     *
 * \Return value     : std_ReturnType  E_OK                                     *
 *                                     E_NOT_OK                                 *
 ********************************************************************************/
 
/********************************************************************************
 *                           END OF FILE : FileName.c                           *
 ********************************************************************************/
 