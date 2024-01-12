/* 
 * File:   hal_gpio.h
 * Author: Ahmed Abdelrazik
 *
 * Created on January 11, 2024, 2:24 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */

#include "../device_config.h"
#include "../compiler.h"
#include "../std_types.h"
#include "hal_gpio_cfg.h"

/* Section : Macros Declaration */

#define MAXIMUM_PORT_NUMBER     0x05
#define MAXIMUM_PIN_NUMBER      0x08

/* Section : Macro Functions Declaration */

#define HWREG8(_X)       (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POSN)      (REG |= (1 << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)    (REG &= ~(1 << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)   (REG ^= (1 << BIT_POSN))
#define READ_BIT(REG, BIT_POSN)     ((REG >> BIT_POSN) & 1)


/* Section : Data Type Declaration */

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_t;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_t;

typedef enum{
    GPIO_OUTPUT = 0,
    GPIO_INPUT
}direction_t;

typedef enum{
    OUTPUT_LOGIC_LOW = 0,
    OUTPUT_LOGIC_HIGH
}logic_t;

typedef struct{
    uint8 port      : 3;
    uint8 pin       : 3;
    uint8 direction : 1;
    uint8 logic     : 1;
}pin_config_t;

/* Section : Function Declaration */

Std_ReturnType hal_gpio_pin_init(pin_config_t *pin_config);
Std_ReturnType hal_gpio_pin_get_direction(pin_config_t *pin_config);
Std_ReturnType hal_gpio_pin_read(pin_config_t *pin_config, uint8 *output);
Std_ReturnType hal_gpio_pin_write(pin_config_t *pin_config);
Std_ReturnType hal_gpio_pin_toggle(pin_config_t *pin_config);

Std_ReturnType hal_gpio_port_init(uint8 port, uint8 direction);
Std_ReturnType hal_gpio_port_get_direction(uint8 port, uint8 *output);
Std_ReturnType hal_gpio_port_read(uint8 port, uint8 *output);
Std_ReturnType hal_gpio_port_write(uint8 port, uint8 logic);
Std_ReturnType hal_gpio_port_toggle(uint8 port);


#endif	/* HAL_GPIO_H */

