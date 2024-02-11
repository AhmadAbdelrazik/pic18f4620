/**
 * @file ecu_led.h
 * 
 * @author Ahmad Abdelrazik (ahmadabdelrazik159@gmail.com)
 * 
 * @linkedin linkedin.com/in/ahmadabdelrazik/
 * @github github.com/AhmadAbdelrazik/
 * 
 * @date 2024-02-11
 * 
 * @brief 
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/** Section : Includes **/

#include "../../MCAL_Layer/HAL_gpio/hal_gpio.h"

/** Section : Macros Definitions **/

/** Section : Data Types **/

typedef struct {
    uint8 pin  : 4;
    uint8 port : 4;
}led_t;


/** Section : Function-like Macros Definition **/

/** Section : Function Declarations **/

/**
 * @brief  Initialize the led
 * 
 * @param led 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_init(led_t *led);


/**
 * @brief Turn the led on
 * 
 * @param led 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_on(led_t *led);

/**
 * @brief 
 * 
 * @param led 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_off(led_t *led);

/**
 * @brief Toggle the Led
 * 
 * @param led 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_led_toggle(led_t *led);

#endif	/* ECU_LED_H */

