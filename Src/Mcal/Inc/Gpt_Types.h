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

#ifndef GPT_TYPES_H
#define GPT_TYPES_H

/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/

#include "std_types.h"
#include "IntCtrl_Types.h"
#include "Gpt_Lcfg.h"
 
/********************************************************************************
 *                        GLOBAL MACROS CONSTANT\FUNCTION                       *
 ********************************************************************************/
 
 #define Total_Numbers_Timer                12u

 #define Gpt_Timer0_16Bit_BASE_ADDRESS                   0x40030000
 #define Gpt_Timer1_16Bit_BASE_ADDRESS                   0x40031000
 #define Gpt_Timer2_16Bit_BASE_ADDRESS                   0x40032000
 #define Gpt_Timer3_16Bit_BASE_ADDRESS                   0x40033000
 #define Gpt_Timer4_16Bit_BASE_ADDRESS                   0x40034000
 #define Gpt_Timer5_16Bit_BASE_ADDRESS                   0x40035000

 #define Gpt_Timer0_32Bit_BASE_ADDRESS                   0x40036000
 #define Gpt_Timer1_32Bit_BASE_ADDRESS                   0x40037000
 #define Gpt_Timer2_32Bit_BASE_ADDRESS                   0x4004C000
 #define Gpt_Timer3_32Bit_BASE_ADDRESS                   0x4004D000
 #define Gpt_Timer4_32Bit_BASE_ADDRESS                   0x4004E000
 #define Gpt_Timer5_32Bit_BASE_ADDRESS                   0x4004F000
 
 #define GPTMCFG(BASE)                                   (*((volatile Gpt_GPTMCFG_BF*)(BASE+0x000)))

 #define GPTMTAMR(BASE)                                  (*((volatile Gpt_GPTMTAMR_BF*)(BASE+0x004)))
 #define GPTMTBMR(BASE)                                  (*((volatile Gpt_GPTMTBMR_BF*)(BASE+0x008)))
 #define GPTMCTL(BASE)                                   (*((volatile Gpt_GPTMCTL_BF*)(BASE+0x00C)))
 #define GPTMIMR(BASE)                                   (*((volatile Gpt_GPTMIMR_BF*)(BASE+0x018)))
 #define GPTMRIS(BASE)                                   (*((volatile Gpt_GPTMRIS_BF*)(BASE+0x01C)))
 #define GPTMICR(BASE)                                   (*((volatile Gpt_GPTMICR_BF*)(BASE+0x024)))

 #define GPTMTAILR(BASE)                                 (*((volatile uint32*)(BASE +0x028)))
 #define GPTMTBILR(BASE)                                 (*((volatile uint32*)(BASE +0x02C)))
 #define GPTMTAPR(BASE)                                  (*((volatile uint32*)(BASE +0x038)))
 #define GPTMTBPR(BASE)                                  (*((volatile uint32*)(BASE +0x03C)))
 #define GPTMTAV(BASE)                                   (*((volatile uint32*)(BASE +0x050)))
 #define GPTMTBV(BASE)                                   (*((volatile uint32*)(BASE +0x054)))
 
 #define SysCtrl_RCGCTIMER                               (*((volatile Gpt_SCGCTIMER_BF*)(SysCtrl_BASE_ADDRESS+0x604)))
 #define SysCtrl_RCGCwTIMER                              (*((volatile Gpt_SCGCTIMER_BF*)(SysCtrl_BASE_ADDRESS+0x65C)))

/********************************************************************************
 *                                  LOCAL DATA                                  *
 ********************************************************************************/
 
/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/

typedef struct
{
    uint32 GPTMCFG                                       :3;
    uint32                                               :29;
} Gpt_GPTMCFG_BF;


typedef enum
{   
    Periodic_OneShot_Clock = 0x0,
    RTC_Clock = 0x1,
    ICU_PWM = 0x4
} Gpt_Configuration;


typedef struct
{
    uint32 R0                                            :1;
    uint32 R1                                            :1;
    uint32 R2                                            :1;
    uint32 R3                                            :1;
    uint32 R4                                            :1;
    uint32 R5                                            :1;
    uint32                                               :24;
} Gpt_SCGCTIMER_BF;

typedef struct
{
    uint32 TAMR                                         :2;
    uint32 TACMR                                        :1;
    uint32 TAAMS	                                    :1;
	uint32 TACDIR	                                    :1;
	uint32 TAMIE	                                    :1;
	uint32 TAWOT	                                    :1;
	uint32 TASNAPS	                                    :1;
	uint32 TAILD	                                    :1;
	uint32 TAPWMIE	                                    :1;
	uint32 TAMRSU	                                    :1;
	uint32 TAPLO	                                    :1;
	uint32 			                                    :20;
} Gpt_GPTMTAMR_BF;

typedef struct
{
    uint32 TBMR                                         :2;
    uint32 TBCMR                                        :1;
    uint32 TBAMS	                                    :1;
	uint32 TBCDIR	                                    :1;
	uint32 TBMIE	                                    :1;
	uint32 TBWOT	                                    :1;
	uint32 TBSNAPS	                                    :1;
	uint32 TBILD	                                    :1;
	uint32 TBPWMIE	                                    :1;
	uint32 TBMRSU	                                    :1;
	uint32 TBPLO	                                    :1;
	uint32 			                                    :20;
} Gpt_GPTMTBMR_BF;

typedef struct
{
    uint32 TAEN                                        :1;
    uint32 TASTALL                                     :1;
    uint32 TAEVENT                                     :2;
    uint32 RTCEN                                       :1;
    uint32 TAOTE	                                   :1;
	uint32 TAPWML	                                   :1;
	uint32 		                                       :1;
	uint32 TBEN		                                   :1;
	uint32 TBSTALL	                                   :1;
	uint32 TBEVENT	                                   :2;
	uint32 			                                   :1;
	uint32 TBOTE	                                   :1;
	uint32 TBPWML	                                   :1;
	uint32 			                                   :17;

} Gpt_GPTMCTL_BF;

typedef struct
{
    uint32 TATOIM	                                   :1;
	uint32 CAMIM	                                   :1;
	uint32 CAEIM	                                   :1;
	uint32 RTCIM	                                   :1;
	uint32 TAMIM	                                   :1;
	uint32 			                                   :3;
	uint32 TBTOIM	                                   :1;
	uint32 CBMIM	                                   :1;
	uint32 CBEIM	                                   :1;
	uint32 TBMIM	                                   :1;
	uint32 			                                   :4;
	uint32 WUEIM	                                   :1;
	uint32 			                                   :15;
} Gpt_GPTMIMR_BF;

typedef struct
{
    uint32 TATORIS	                                   :1;
	uint32 CAMRIS	                                   :1;
	uint32 CAERIS	                                   :1;
	uint32 RTCRIS	                                   :1;
	uint32 TAMRIS	                                   :1;
	uint32			                                   :3;
	uint32 TBTORIS	                                   :1;
	uint32 CBMRIS	                                   :1;
	uint32 CBERIS	                                   :1;
	uint32 TBMRIS	                                   :1;
	uint32			                                   :4;
	uint32 WUERIS	                                   :1;
} Gpt_GPTMRIS_BF;

typedef struct
{
    uint32 TATOCINT	                                   :1;
	uint32 CAMCINT	                                   :1;
	uint32 CAECINT	                                   :1;
	uint32 RTCCINT	                                   :1;
	uint32 TAMCINT	                                   :1;
	uint32 			                                   :3;
	uint32 TBTOCINT	                                   :1;
	uint32 CBMCINT	                                   :1;
	uint32 CBECINT	                                   :1;
	uint32 TBMCINT	                                   :1;
	uint32 			                                   :4;
	uint32 WUECINT	                                   :1;
	uint32 			                                   :15;
} Gpt_GPTMICR_BF;

typedef struct
{
    uint32 TAPSR	:8;
	uint32 TAPSRH	:8;
	uint32			:16;
} Gpt_GPTMTAPR_BF;

typedef struct
{
    uint32 TBPSR	:8;
	uint32 TBPSRH	:8;
	uint32			:16;
} Gpt_GPTMTBPR_BF;

typedef IntCtrl_Interrupt_Type Gpt_Timer_InterruptType;

typedef enum
{
    Timer_0_16_Bit = 0,
    Timer_1_16_Bit = 1,
    Timer_2_16_Bit = 2,
    Timer_3_16_Bit = 3,
    Timer_4_16_Bit = 4,
    Timer_5_16_Bit = 5,
    Timer_0_32_Bit = 6,
    Timer_1_32_Bit = 7,
    Timer_2_32_Bit = 8,
    Timer_3_32_Bit = 9,
    Timer_4_32_Bit = 10,
    Timer_5_32_Bit = 11
} Gpt_Channel_Type;

typedef enum
{
    Full = 0x0,
    Half = 0x4
} Gpt_Channel_SizeType;

typedef enum
{
    Gpt_Disable = 0,
    Gpt_Enable = 1
} Gpt_EnableType;

typedef uint64 Gpt_ChannelTick_FreqType;

typedef enum
{
    Down = 0x0,
    Up = 0x1
} Gpt_Direction_Type;

typedef enum
{
    Gpt_Normal_Mode = 0,
    Gpt_Sleep_Mode = 1
} Gpt_Mode_Type;

typedef enum
{
    Gpt_Channel_OneShot_Mode = 0x1,
    Gpt_Channel_Continous_Mode = 0x2,
	Gpt_Channel_Capture_Mode = 0x3
} Gpt_Channel_ModeType;

typedef uint64 Gpt_ValueType;

typedef void (*Gpt_Notification_Type)(void);

typedef uint8 Gpt_Notification_Priority;

typedef struct
{
    Gpt_Channel_Type Gpt_ChannelID;
   
    Gpt_EnableType Gpt_IsEnabled;

    Gpt_Direction_Type Gpt_Direction;
    
    Gpt_ChannelTick_FreqType Gpt_Freq;
   
    Gpt_Channel_ModeType Gpt_Mode;
    
    Gpt_Notification_Type Gpt_Notify;
    
    Gpt_Notification_Priority Gpt_NotifyPriorty;
} Gpt_ChannelConfigType;

typedef uint8 Gpt_PreDeff_TimerType;

typedef struct
{
    Gpt_ChannelConfigType GptChannel[Total_Numbers_Timer];
} Gpt_ConfigType;

/********************************************************************************
 *                           LOCAL FUNCTION PROTOTYPES                          *
 ********************************************************************************/
 
/********************************************************************************
 *                                LOCAL FUNCTIONS                               *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTIONS                               *
 ********************************************************************************/ 

 
 #endif /* GPT_TYPES_H */
/********************************************************************************
 *                           END OF FILE : Gpt_Types.h                          *
 ********************************************************************************/
 