/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : Dio.c                                                     *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : Dio                                                       *
 *                                                                              *
 *      Description : Source File for Dio Modules Driver                        *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 *                                   INCLUDES                                   *
 ********************************************************************************/
 
#include "Dio.h"
#include "Dio_Types.h"
#include "std_types.h"
#include "common_macros.h"

/********************************************************************************
 *                                GLOBAL FUNCTION                               *
 ********************************************************************************/

/*********************************************************************************
 * \Syntax           : Dio_ReadChannel                                           *
 * \Description      : Function for Dio to Read Channel API                      *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType                              *
 * \Parameters (out) : Dio_level_Type                                            *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 *********************************************************************************/
Dio_Level_Type Dio_ReadChannel (Dio_ChannelType Channel_ID)
{
    if (Channel_ID >= Number_Configured_Channels)
    {
        return Dio_Level_ERROR;
    }

    switch (ConfigTypes.Channels[Channel_ID].Port_ID)
    {
        case PORT_A:
            if ( GET_BIT ( Port_A_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;

        case PORT_B:
            if ( GET_BIT ( Port_B_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;

        case PORT_C:
            if ( GET_BIT ( Port_C_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;

        case PORT_D:
            if ( GET_BIT ( Port_D_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;

        case PORT_E:
            if ( GET_BIT ( Port_E_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;

        case PORT_F:
            if ( GET_BIT ( Port_F_GPIODATA , ConfigTypes.Channels[Channel_ID].Pin_ID ) == Dio_Level_HIGH )
            {
                return Dio_Level_HIGH;
            }
            else
            {
                return Dio_Level_LOW;
            }
        break;
    
        default:
            return Dio_Level_ERROR;
        break;
    }
}

/*********************************************************************************
 * \Syntax           : Dio_WriteChannel                                          *
 * \Description      : Function for Dio to Write Channel API                     *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType, Level - Dio_Level_Type      *
 * \Parameters (out) : None                                                      *
 * \Return value     : void                                                      *
 *                                                                               *
 *********************************************************************************/ 
void Dio_WriteChannel (Dio_ChannelType Channel_ID, Dio_Level_Type Level)
{
    switch (ConfigTypes.Channels[Channel_ID].Port_ID)
    {
    case PORT_A:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_A_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
        else
        {
            CLEAR_BIT ( Port_A_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;

    case PORT_B:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_B_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
        else
        {
            CLEAR_BIT ( Port_B_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;
    
    case PORT_C:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_C_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
        else
        {
            CLEAR_BIT ( Port_C_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;

    case PORT_D:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_D_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
        else
        {
            CLEAR_BIT ( Port_D_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;

    case PORT_E:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_E_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
        else
        {
            CLEAR_BIT ( Port_E_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;

    case PORT_F:
        if (Level == Dio_Level_HIGH)
        {
            SET_BIT ( Port_F_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }

        else
        {
            CLEAR_BIT ( Port_F_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID );
        }
    break;
    }

    if (Channel_ID >= Number_Configured_Channels)
    {
        return;
    }
}

/*********************************************************************************
 * \Syntax           : Dio_FlipChannel                                           *
 * \Description      : Function for Dio to Flip then Read Channel API            *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Channel_ID - Dio_ChannelType                              *
 * \Parameters (out) : Dio_level_Type                                            *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 ********************************************************************************/
Dio_Level_Type Dio_FlipChannel (Dio_ChannelType Channel_ID)
{
    if (Channel_ID >= Number_Configured_Channels)
    {
        return Dio_Level_ERROR;
    }

    switch (ConfigTypes.Channels[Channel_ID].Port_ID)
    {
    case PORT_A:
        if (GET_BIT (Port_A_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_A_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_A_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;
    
    case PORT_B:
        if (GET_BIT (Port_B_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_B_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_B_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;

    case PORT_C:
        if (GET_BIT (Port_C_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_C_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_C_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;

    case PORT_D:
        if (GET_BIT (Port_D_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_D_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_D_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;

    case PORT_E:
        if (GET_BIT (Port_E_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_E_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_E_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;

    case PORT_F:
        if (GET_BIT (Port_F_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID)==Dio_Level_HIGH)
        {
            CLEAR_BIT (Port_F_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_LOW;
        }
        else
        {
            SET_BIT (Port_F_GPIODATA, ConfigTypes.Channels[Channel_ID].Pin_ID);
            return Dio_Level_HIGH;
        }
        break;
    }   
}

/*********************************************************************************
 * \Syntax           : Dio_ReadPort                                              *
 * \Description      : Function for Dio to Read Port API                         *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Port_ID - Dio_PortType                                    *
 * \Parameters (out) : Dio_Port_levelType                                        *
 * \Return value     : High, Low, Error                                          *
 *                                                                               *
 ********************************************************************************/
Dio_Port_LevelType Dio_ReadPort (Port_PortType PortID)
{
    switch (ConfigTypes.Channels[PortID].Port_ID)
    {
    case PORT_A:
        return (Dio_Port_LevelType)Port_A_GPIODATA;
        break;
    
    case PORT_B:
        return (Dio_Port_LevelType)Port_B_GPIODATA;
        break;
    
    case PORT_C:
        return (Dio_Port_LevelType)Port_C_GPIODATA;
        break;
    
    case PORT_D:
        return (Dio_Port_LevelType)Port_D_GPIODATA;
        break;

    case PORT_E:
        return (Dio_Port_LevelType)Port_E_GPIODATA;
        break;

    case PORT_F:
        return (Dio_Port_LevelType)Port_F_GPIODATA;
        break;
    }
}

/*********************************************************************************
 * \Syntax           : Dio_ReadPort                                              *
 * \Description      : Function for Dio to Write Port API                        *
 *                                                                               *
 * \Sync\Async       : Synchronous                                               *
 * \Reentrancy       : Reentrant                                                 *
 * \Parameters (in)  : Port_ID - Dio_PortType, Level Dio_Port_LevelType          *
 * \Parameters (out) : None                                                      *
 * \Return value     : void                                                      *
 *                                                                               *
 ********************************************************************************/
void Dio_WritePort ( Dio_PortType PortID, Dio_Port_LevelType Level)
{
    switch (ConfigTypes.Channels[PortID].Port_ID)
    {
    case PORT_A:
        Port_A_GPIODATA = Level;
        break;

    case PORT_B:
        Port_B_GPIODATA = Level;
        break;
    
    case PORT_C:
        Port_C_GPIODATA = Level;
        break;
    
    case PORT_D:
        Port_D_GPIODATA = Level;
        break;

    case PORT_E:
        Port_E_GPIODATA = Level;
        break;
    
    case PORT_F:
        Port_F_GPIODATA = Level;
        break;
    }
}

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
 *                             END OF FILE : Dio.c                              *
 ********************************************************************************/