/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Port.c                                                    *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Port                                                      *
 *                                                                              *
 *      Description : Source file for Port Module Driver                               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
 #include "Port.h"
 #include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/mcu_hw.h"
 #include "D:/Embedded_C/Advanced_Embedded_Systems_EgFWD/Projects/uVisionProject/Sprints_ARM_MC01/Src/LIBRARIES/Common/common_macros.h"
 
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
 * \Syntax           : Port_Initialize                                          *
 * \Description      : Function to Setup the Port Configuration                 *
 *                     1- Setup Pin as Digital Gpio Pin                         *
 *                     2- Setup the direction of GPIO Pins                      *
 *                     3- Set Initial Values for the Gpio Pin                   *
 *                     4- Setup the mode of the Gpio Pin                        *
 *                     5- setup the internal Resistor for I/O Pins              *
 *                     6- Setup the output current in case of Output Pin        *
 *                                                                              *
 * \Sync\Async       : Synchronous                                              *
 * \Reentrancy       : Reentrant                                                *
 * \Parameters (in)  : ConfigPTR - Port_ConfigType                              *
 * \Parameters (out) : None                                                     *
 * \Return value     : Void                                                     *
 *                                                                              *
 ********************************************************************************/ 
void Port_Initalize(const Port_ConfigType *ConfigPTR)
{
    uint8 Pin = 0;

    volatile uint32 *PortPTR = NULL_PTR;

    if (ConfigPTR == NULL_PTR)
    {
        return;
    }
    
    for (Pin = 0; Pin < Total_Pin_Num_In_Ports; Pin++)
    {
        if (ConfigPTR ->PinConfigType[Pin].Is_Enabled == Channel_Disable)
        {
            continue;
        }

        switch (ConfigPTR ->PinConfigType[Pin].Port_Type)
        {
        case PORT_A:
            PortPTR = (volatile uint32*)PortA_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortA =1;
        break;

        case PORT_B:
            PortPTR = (volatile uint32*)PortB_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortB =1;
        break;

        case PORT_C:
            PortPTR = (volatile uint32*)PortC_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortC =1;
        break;

        case PORT_D:
            PortPTR = (volatile uint32*)PortD_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortD =1;
        break;

        case PORT_E:
            PortPTR = (volatile uint32*)PortE_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortE =1;
        break;

        case PORT_F:
            PortPTR = (volatile uint32*)PortF_BASE_ADDRESS;
            SysCtrl_RCGCGPIO.BF.GPIO_PortF =1;
        break;
        }

        if ( ((ConfigPTR ->PinConfigType[Pin].Port_Type == PORT_D) && (ConfigPTR ->PinConfigType[Pin].Pin_Type==PIN_7)) || ((ConfigPTR ->PinConfigType[Pin].Port_Type == PORT_F) && (ConfigPTR ->PinConfigType[Pin].Pin_Type==PIN_0)) )
        {
            (*(volatile uint32*)((volatile uint8*)PortPTR + GPIOCR_OFFSET)) = 0x4C4F434B;

            SET_BIT (*(volatile uint32*)((volatile uint8*)PortPTR + GPIOCR_OFFSET),ConfigPTR ->PinConfigType[Pin].Pin_Type);
        }

        else if (((ConfigPTR ->PinConfigType[Pin].Port_Type == PORT_C) && (ConfigPTR ->PinConfigType[Pin].Pin_Type < PIN_4 )))
        {
            /* JTAG/ SWD Pins */
            continue;
        }

        else
        {
            /* Do Nothing */
        }
        
        switch (ConfigPTR ->PinConfigType[Pin].Pin_Mode_Type)
        {
        case Dio_Mode:
            CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIOAMSEL_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

            CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIOAFSEL_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

					  *(volatile uint32*)((volatile uint8*)PortPTR + GPIOPCTL_OFFSET) &= ~ (0x0000000F << (ConfigPTR ->PinConfigType[Pin].Pin_Type *4));
            
            SET_BIT  ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODEN_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
            break;
        
        case ICU_Mode:
            /* Do Nothing */
            break;

        case ADC_Mode:
            /* Do Nothing */
            break;    

        default: /* Default in Dio Mode */
            CLEAR_BIT (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOAMSEL_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

            CLEAR_BIT (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOAFSEL_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

            *(volatile uint32*)((volatile uint8*)PortPTR + GPIOPCTL_OFFSET) &= ~ (0x0000000F << (ConfigPTR ->PinConfigType[Pin].Pin_Type *4));
            
            SET_BIT   (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIODEN_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
            break;
        }

        if (ConfigPTR ->PinConfigType[Pin].Pin_Direction_Type == OUTPUT)
        {
            SET_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIODIR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

            if (ConfigPTR ->PinConfigType[Pin].Pin_Level_Type == Pin_Level_HIGH)
            {
                SET_BIT (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIODATA_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
            }
            else
            {
                CLEAR_BIT (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIODATA_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
            }

            switch (ConfigPTR ->PinConfigType[Pin].Pin_OutputCurrent_Type)
            {
            case Current_2mA:
                SET_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR2R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                
                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR4R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR8R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            case Current_4mA:
                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR2R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                
                SET_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR4R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR8R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            case Current_8mA:
                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR2R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                
                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR4R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                SET_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR8R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            
            default:
                SET_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR2R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR4R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT ( *(volatile uint32*) ((volatile uint8*)PortPTR + GPIODR8R_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            }

        }

        else if ( ConfigPTR ->PinConfigType[Pin].Pin_Direction_Type == OUTPUT)
        {
            CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIODIR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

            switch ( ConfigPTR ->PinConfigType[Pin].Pin_InternalAttach_Type)
            {
            case Pull_UP:
                SET_BIT    (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPUR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPDR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOODR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOSLR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            
            case Pull_DOWN:
                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPUR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                SET_BIT    (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPDR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOODR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOSLR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;

            case Open_Drain:
                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPUR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPDR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                SET_BIT    (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOODR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOSLR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;

            case Slew_Rate:
                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPUR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPDR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOODR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                SET_BIT    (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOSLR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;    

            default: /* Pull Up mode */
                SET_BIT    (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPUR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOPDR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOODR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);

                CLEAR_BIT  (*(volatile uint32*) ((volatile uint8*)PortPTR + GPIOSLR_OFFSET), ConfigPTR ->PinConfigType[Pin].Pin_Type);
                break;
            }
        }
        
        else
        {
            return;
        }
    }
}

/********************************************************************************
 *                           END OF FILE : Port.c                            *
 ********************************************************************************/
 