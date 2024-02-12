/**
 * @file ecu_led.c
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

#include "ecu_led.h"


Std_ReturnType ecu_led_init(led_t *led) {
    Std_ReturnType ret = E_OK;
    
    if (led == NULL || led->pin >= MAXIMUM_PIN_NUMBER || led->port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led_pin = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_LOW,
            .pin = (led->pin),
            .port = (led->port)
        };
        
        ret = hal_gpio_pin_init(&led_pin);
    }
    
    return ret;
}
Std_ReturnType ecu_led_on(led_t *led) {

    Std_ReturnType ret = E_OK;
    
    if (led == NULL || led->pin >= MAXIMUM_PIN_NUMBER || led->port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led_pin = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_HIGH,
            .pin = (led->pin),
            .port = (led->port)
        };
        
        ret = hal_gpio_pin_write(&led_pin, led_pin.logic);
    }
    
    return ret;
}
Std_ReturnType ecu_led_off(led_t *led) {
    
    Std_ReturnType ret = E_OK;
    
    if (led == NULL || led->pin >= MAXIMUM_PIN_NUMBER || led->port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led_pin = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_LOW,
            .pin = (led->pin),
            .port = (led->port)
        };
        
        ret = hal_gpio_pin_write(&led_pin, led_pin.logic);
    }
    
    return ret;
}

Std_ReturnType ecu_led_toggle(led_t *led) {
        
    Std_ReturnType ret = E_OK;
    
    if (led == NULL || led->pin >= MAXIMUM_PIN_NUMBER || led->port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led_pin = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_LOW,
            .pin = (led->pin),
            .port = (led->port)
        };
        ret = hal_gpio_pin_toggle(&led_pin);
    }
    
    return ret;
}
