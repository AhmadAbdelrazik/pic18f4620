/**
 * @file ecu_push_button.c
 * @author Ahmad Abdelrazik (ahmadabdelrazik159@gmail.com)
 * @brief 
 * 
 * @version 0.1
 * @date 2024-01-31
 * 
 */

#include "ecu_push_button.h"



Std_ReturnType ecu_push_button_initialize(const button_t *btn) {
    Std_ReturnType ret = E_OK;

    if (btn == NULL) {
        ret = E_NOT_OK;
    } 
    else {
        ret = hal_gpio_pin_init(&(btn->button_pin));
    }

    return ret;
}


Std_ReturnType ecu_push_button_read_state(const button_t *btn, button_state_t *btn_state) {
    Std_ReturnType ret = E_OK;
    logic_t pin_logic_status = OUTPUT_LOGIC_LOW;

    // NULL pointer check
    if (btn == NULL || btn_state == NULL) 
        return E_NOT_OK;
    else {/* NULL */}

    // Read logic on the pin, return either HIGH or LOW
    hal_gpio_pin_read(&(btn->button_pin), &(pin_logic_status));        
    
    // In case it was active high -> PRESSED at logic HIGH
    if (btn->button_connection == BUTTON_ACTIVE_HIGH)
    {
        if (pin_logic_status == OUTPUT_LOGIC_HIGH)
            *btn_state = BUTTON_PRESSED;
        else if (pin_logic_status == OUTPUT_LOGIC_LOW)
            *btn_state = BUTTON_RELEASED;
        else
            ret = E_NOT_OK;
    }
    // In case it was active low -> PRESSED at logic LOW
    else if (btn->button_connection == BUTTON_ACTIVE_LOW)
    {
        if (pin_logic_status == OUTPUT_LOGIC_HIGH)
            *btn_state = BUTTON_RELEASED;
        else if (pin_logic_status == OUTPUT_LOGIC_LOW)
            *btn_state = BUTTON_PRESSED;
        else
            ret = E_NOT_OK;
    }
    else {
        ret = E_NOT_OK;
    }

    return ret;
}