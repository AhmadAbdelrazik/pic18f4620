/**
 * @file ecu_push_button.h
 * 
 * @author Ahmad Abdelrazik (ahmadabdelrazik159@gmail.com)
 * 
 * @linkedin linkedin.com/in/ahmadabdelrazik/
 * @github github.com/AhmadAbdelrazik/
 * 
 * @date 2024-01-31
 * 
 * @brief 
 */

#ifndef ECU_PUSH_BUTTON_H
#define ECU_PUSH_BUTTON_H

/********* Section : Includes ************/

#include "../../MCAL_Layer/HAL_gpio/hal_gpio.h"

/********* Section : Data Type Definition ************/

typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH = 0,
    BUTTON_ACTIVE_LOW
}button_active_t;

typedef struct{
    pin_config_t button_pin;
    uint8 button_state : 1;
    uint8 button_connection : 1;
    uint8 reserved : 6;
}button_t;

/********* Section : Macro Declaration ************/

/********* Section : Function like Macro Definitions ************/

Std_ReturnType ecu_push_button_initialize(const button_t *btn);
Std_ReturnType ecu_push_button_read_state(const button_t *btn, button_state_t *btn_state);

/********* Section : Function Definitions ************/

#endif