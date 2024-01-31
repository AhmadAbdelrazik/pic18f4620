
#include "ecu_led.h"


Std_ReturnType ecu_led_init(uint8 pin, uint8 port) {
    Std_ReturnType ret = E_OK;
    
    if (pin >= MAXIMUM_PIN_NUMBER || port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_LOW,
            .pin = pin,
            .port = port
        };
        
        ret = hal_gpio_pin_init(&led);
    }
    
    return ret;
}
Std_ReturnType ecu_led_on(uint8 pin, uint8 port) {

    Std_ReturnType ret = E_OK;
    
    if (pin >= MAXIMUM_PIN_NUMBER || port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_HIGH,
            .pin = pin,
            .port = port
        };
        
        ret = hal_gpio_pin_write(&led, led.logic);
    }
    
    return ret;
}
Std_ReturnType ecu_led_off(uint8 pin, uint8 port) {
    
    Std_ReturnType ret = E_OK;
    
    if (pin >= MAXIMUM_PIN_NUMBER || port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led = {
            .direction = GPIO_OUTPUT,
            .logic = OUTPUT_LOGIC_LOW,
            .pin = pin,
            .port = port
        };
        
        ret = hal_gpio_pin_write(&led, led.logic);
    }
    
    return ret;
}

Std_ReturnType ecu_led_toggle(uint8 pin, uint8 port) {
        
    Std_ReturnType ret = E_OK;
    
    if (pin >= MAXIMUM_PIN_NUMBER || port >= MAXIMUM_PORT_NUMBER) 
        ret = E_NOT_OK;
    else {
        pin_config_t led = {
            .direction = GPIO_OUTPUT,
            .pin = pin,
            .port = port
        };
        
        ret = hal_gpio_pin_toggle(&led);
    }
    
    return ret;
}
