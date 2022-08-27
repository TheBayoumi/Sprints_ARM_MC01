/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : main.h                                                    *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : main                                                      *
 *                                                                              *
 *      Description : Source file for the main configuration                    *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/*******************************************************************************
 *                                   INCLUDES                                  *
 *******************************************************************************/

#include "main.h"

/********************************************************************************
 *                                 GLOBAL DATA                                  *
 ********************************************************************************/


/********************************************************************************
 *                         GLOBAL FUNCTIONS PROTOTYPES                          *
 ********************************************************************************/

/********************************************************************************
 *                               GLOBAL FUNCTION                                *
 ********************************************************************************/

/********************************************************************************
*                                 LOCAL DATA                                    *
 ********************************************************************************/
 
/********************************************************************************
 *                          LOCAL FUNCTION PROTOTYPES                           *
 ********************************************************************************/
 
/********************************************************************************
 *                               LOCAL FUNCTIONS                                *
 ********************************************************************************/

int main (void)
{
    /* 
    Enter The On Time of LED in Seconds
        1- Press Switch 1 to confirm the time, the blue LED will blink as confirmation.
        2- Press Switch 2 to increment the number of seconds, the green LED will blink with every press
    */
    uint8 TimeON = Get_NumOfPress (Buton_1, LED_2, Buton_2,LED_3,Pull_UP);

/* 
    Enter The OFF Time of LED in Seconds
        1- Press Switch 1 to confirm the time, the blue LED will blink as confirmation.
        2- Press Switch 2 to increment the number of seconds, the green LED will blink with every press
    */
    uint8 TimeOFF = Get_NumOfPress (Buton_1, LED_2, Buton_2,LED_3,Pull_UP);

    while (1)
    {
        Blinking_Start (Blink_Gpt, LED_1,200,TimeON,TimeOFF);
    }
    
    return 0;
}

/********************************************************************************
 *                           END OF FILE : main.h                               *
 ********************************************************************************/