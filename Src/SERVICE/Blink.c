/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Blink.c                                                   *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Blink                                                     *
 *                                                                              *
 *      Description : Source file for the Button Driver                         *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/


/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/SERVICE/Inc/Blink.h"

/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/


void Blinking_CallBack(void)
{
    LED_Toggle(DeviceChannel);
    Flag = 1;
}


/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTION                                *
 ********************************************************************************/

/********************************************************************************
 * \Syntax           : Blinking_Start                                           *
 * \Description      : Function to Initialize and Start Blinkning               *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : TimerChannel - Service_Timer_Channel                     *
 *                     DeviceChannel - Service_Channel                          *
 *                     Time - Service_Time_Type                                 *
 *                     HighPeriod - Service_High_Period                         *
 *                     LowPeriod - Service_Low_Period                           *
 *                                                                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Blinking_Start(Service_Timer_Channel TimerChannel, Service_Channel DeviceChannel,Service_Time_Type Time, Service_High_Period HighPeriod,Service_Low_Period LowPeriod)
{
    /* LED Initialization */
    LED_Initialize();

    Dio_WriteChannel (DeviceChannel, Dio_Level_HIGH);

    /* Initialized by GPTM */
    TimerChannel = TimerChannel;

    
    Gpt_Config_Types.GptChannel[TimerChannel].Gpt_IsEnabled = Gpt_Enable;

    Gpt_Config_Types.GptChannel[TimerChannel].Gpt_Mode = Gpt_Channel_OneShot_Mode;

    Gpt_Config_Types.GptChannel[TimerChannel].Gpt_Notify = Blinking_CallBack;

    Gpt_Initialize(&Gpt_Config_Types.GptChannel[TimerChannel]);;

    Service_Timer_Channel Period = 0;

    while (Time > 0)
    {
        /* HighPeriod Delay */
        Period = HighPeriod;

        if (Period > Time)
        {
            Period = Time;
        }
        
        if (Period > 0)
        {
            Gpt_StartTimer(TimerChannel,Seconds(Period));

            while (Flag != 1);
            
            Flag = 0;
            
            Time = Time - Period;
        }
        
        if (Time < 1)
        {
            break;
        }
        
        /* LowPeriod Delay */
        Period = LowPeriod;

        if (Period > Time)
        {
            Period = Time;
        }

        Gpt_StartTimer (TimerChannel, Seconds(Period));

        while (Flag != 1);
            
        Flag = 0;
            
        Time = Time - Period;
    }
}

/********************************************************************************
 * \Syntax           : Blinking_Stop                                            *
 * \Description      : Function to Stop Blinking                                *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : DeviceChannel - Service_Channel                          *
 *                                                                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : void                                                     *
 *                                                                              *
 ********************************************************************************/
void Blinking_Stop (Service_Channel DeviceChannel)
{
    /* Stop the Timer  */
    Gpt_StopTimer(TimerChannel);

    /* Turn OFF the LED */
    LED_OFF(DeviceChannel);
}


/********************************************************************************
*                                 LOCAL DATA                                    *
 ********************************************************************************/
 
/********************************************************************************
 *                          LOCAL FUNCTION PROTOTYPES                           *
 ********************************************************************************/
 
/********************************************************************************
 *                               LOCAL FUNCTIONS                                *
 ********************************************************************************/

/********************************************************************************
 *                           END OF FILE : Blink.c                              *
 ********************************************************************************/