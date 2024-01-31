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
 * @brief Initialize the led 
 * 
 * @param pin : Pin number 
 * @param port : Port Number
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_init(uint8 pin, uint8 port);


/**
 * @brief Turn the led on
 * 
 * @param pin : Pin number 
 * @param port : Port Number
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_on(uint8 pin, uint8 port);

/**
 * @brief Turn the led off
 * 
 * @param pin : Pin number 
 * @param port : Port Number
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_off(uint8 pin, uint8 port);

/**
 * @brief Toggle the Led
 * 
 * @param pin : Pin number 
 * @param port : Port Number
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_toggle(uint8 pin, uint8 port);




#endif	/* ECU_LED_H */

