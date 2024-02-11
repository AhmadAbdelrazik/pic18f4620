/**
 * @file std_types.h
 * 
 * @author Ahmad Abdelrazik (ahmadabdelrazik159@gmail.com)
 * 
 * @linkedin linkedin.com/in/ahmadabdelrazik/
 * @github github.com/AhmadAbdelrazik/
 * 
 * @date 2024-01-11
 * 
 * @brief 
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* Section : Includes */

#include "std_libraries.h"
#include <pic18f4620.h>

/* Section : User Defined Data Types */

typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed char             sint8;
typedef signed short            sint16;
typedef signed long             sint32;
typedef signed long long        sint64;

typedef uint8 Std_ReturnType;

/* Section : Macros */

#define E_NOT_OK                (Std_ReturnType)0x01
#define E_OK                    (Std_ReturnType)0x00

#define STD_HIGH                0x01
#define STD_LOW                 0x00

#define STD_ON                  0x01
#define STD_OFF                 0x00

#define STD_ACTIVE              0x01
#define STD_IDLE                0x00



#endif	/* STD_TYPES_H */

