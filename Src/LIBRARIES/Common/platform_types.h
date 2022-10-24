/********************************************************************************
 *                            * FILE DESCRIPTION *                              *
 *                            ********************                              *
 *                                                                              *
 *      File        : platform_types.h                                          *
 *                                                                              *
 *      Component   : -                                                         *
 *                                                                              *
 *      Module      : -                                                         *
 *                                                                              *
 *      Description : Contains types that dependent on platform - CortexM4      *
 *                                                                              *
 *      Author      : Mahmoud Bayoumi                                           *
 *                                                                              *
 ********************************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/********************************************************************************
 *                                    INCLUDES                                  *
 ********************************************************************************/



/********************************************************************************
 *                              GLOBAL CONSTANT MACROS                          *
 ********************************************************************************/

#define WORD_LENGHT_BIT             (32u)
#define WORD_LENGHT_BYTE            (4u)

#define BIG_ENDIAN_BIT_ORDER        (0u)            /* Big endian bit ordering */
#define LITTLE_ENDIAN_BIT_ORDER     (1u)            /* Little endian bit ordering */

#define BIG_ENDIAN_BYTE_ORDER       (0u)           /* Big endian byte ordering */
#define LITTLE_ENDIAN_BYTE_ORDER    (1u)           /* Little endian byte ordering */

#define CPU_BIT_ORDER       LITTLE_ENDIAN_BIT_ORDER     /*little endian bit ordering*/
#define CPU_BYTE_ORDER      LITTLE_ENDIAN_BYTE_ORDER    /*little endian byte ordering*/

/* Boolean Values */
#ifndef FALSE
#define FALSE                       (0u)
#endif

#ifndef TRUE
#define TRUE                        (1u)
#endif

/********************************************************************************
 *                         GLOBAL DATA TYPES AND STRUCTURE                      *
 ********************************************************************************/

/* Boolean Data Type */
typedef unsigned char boolean;

typedef unsigned char uint8; /*           0 .. 255              */
typedef signed char sint8;   /*        -128 .. +127             */

typedef unsigned short uint16; /*           0 .. 65535            */
typedef signed short sint16;   /*      -32768 .. +32767           */

typedef unsigned long uint32; /*           0 .. 4294967295       */
typedef signed long sint32;   /* -2147483648 .. +2147483647      */

typedef unsigned long long uint64; /*       0 .. 18446744073709551615  */
typedef signed long long sint64;   /* -9223372036854775808 .. 9223372036854775807 */

typedef float float32;
typedef double float64;

#endif /* PLATFORM_TYPES_H_ */

/********************************************************************************
 *                          END OF FILE : platform_types.h                      *
 ********************************************************************************/