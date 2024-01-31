/* 
 * File:   ecu_led.h
 * Author: Ahmed Abdelrazik
 *
 * Created on January 11, 2024, 2:20 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/** Section : Includes **/

#include "../../MCAL_Layer/HAL_gpio/hal_gpio.h"

/** Section : Data Types **/

/** Section : Macros Definitions **/

/** Section : Function-like Macros Definition **/

/** Section : Function Declarations **/

/**
 * @brief 
 * 
 * @param pin 
 * @param port 
 * @return Std_ReturnType 
 */
Std_ReturnType ecu_led_init(uint8 pin, uint8 port);
Std_ReturnType ecu_led_on(uint8 pin, uint8 port);
Std_ReturnType ecu_led_off(uint8 pin, uint8 port);
Std_ReturnType ecu_led_toggle(uint8 pin, uint8 port);




#endif	/* ECU_LED_H */

