/**
 * @file ecu_keypad.h
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

#ifndef ECU_KEYPAD_H
#define ECU_KEYPAD_H

/********* Section : Includes ************/

#include "../../MCAL_Layer/HAL_gpio/hal_gpio.h"

/********* Section : Macro Declaration ************/

#define ECU_KEYPAD_ROW          4
#define ECU_KEYPAD_COLUMN       4

/********* Section : Data Type Definition ************/

typedef struct {
    pin_config_t row[ECU_KEYPAD_ROW];
    pin_config_t column[ECU_KEYPAD_COLUMN];
}keypad_t;


/********* Section : Function like Macro Definitions ************/

/********* Section : Function Definitions ************/

/**
 * @brief initialize the keypad and it's pins.
 * 
 * @param keypad 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_keypad_initialize(const keypad_t *keypad);

/**
 * @brief get the value pressed.
 * 
 * @param keypad 
 * @param value : store the pressed value, return 0 if no button is pressed.
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType ecu_keypad_get_value(const keypad_t *keypad, uint8 *value);

#endif
