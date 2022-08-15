/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : std_types.h                                               *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Provision of Standard Types                               *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/********************************************************************************
 *                                    INCLUDES                                  *
 ********************************************************************************/

#include "platform_types.h"
#include "common_macros.h"

/********************************************************************************
 *                              GLOBAL CONSTANT MACROS                          *
 ********************************************************************************/

#define STD_HIGH        (1u)            /* Physical state 5V or 3.3V */
#define STD_LOW         (0u)            /* Physical state 0V */

#define STD_ACTIVE      (1u)            /* Logical state active */
#define STD_IDLE        (0u)            /* Logical state idle */

#define STD_ON          (1u)
#define STD_OFF         (0u)

#define STD_ENABLE      (1u)
#define STD_DISABLE     (0u)

/* NULL_PTR define with a void pointer to zero definition*/
#define NULL_PTR ((void *)0)

/* INLINE  define for abstraction of the keyword inline*/
#define INLINE          inline

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline" 
   if this is supported at all. */
#define LOCAL_INLINE    static inline

/********************************************************************************
 *                         GLOBAL DATA TYPES AND STRUCTURE                      *
 ********************************************************************************/

typedef enum
{
    E_OK,
    E_NOT_OK
}STD_ReturnType;

typedef void(*ptr_STD_ReturnType)(void);

#endif /* STD_TYPE_H_ */

/********************************************************************************
 *                              END OF FILE : std_types.h                       *
 ********************************************************************************/
