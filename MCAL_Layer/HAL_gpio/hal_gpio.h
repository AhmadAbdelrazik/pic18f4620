/**
 * @file hal_gpio.h
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


/**
 * @brief Initialize pin. 
 * 
 * @param pin_config 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_pin_init(pin_config_t *pin_config);

/**
 * @brief  Read the pin direction.
 * 
 * @param pin_config 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_pin_get_direction(pin_config_t *pin_config);

/**
 * @brief Read the pin input at input mode. 
 * 
 * @param pin_config 
 * @param output : Store the read output 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_pin_read(pin_config_t *pin_config, uint8 *output);


/**
 * @brief Write logic to the pin output at output mode.
 * 
 * @param pin_config 
 * @param logic 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_pin_write(pin_config_t *pin_config, uint8 logic);

/**
 * @brief Toglle logic written to the pin output at output mode. 
 * 
 * @param pin_config 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_pin_toggle(pin_config_t *pin_config);



/**
 * @brief Initialize the port. 
 * 
 * @param port 
 * @param direction 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_port_init(uint8 port, uint8 direction);

/**
 * @brief Read the output direction for the whole port 
 * 
 * @param port 
 * @param output : store the pin directions in a 8-bit memory.  
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_port_get_direction(uint8 port, uint8 *output);

/**
 * @brief Read all values stored in the input register.
 * 
 * @param port 
 * @param output : return the input register values 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_port_read(uint8 port, uint8 *output);

/**
 * @brief write logic to the output register
 * 
 * @param port 
 * @param logic 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_port_write(uint8 port, uint8 logic);

/**
 * @brief Toggle Values in the output register 
 * 
 * @param port 
 * @return Std_ReturnType : E_OK if no errors, else E_NOT_OK
 */
Std_ReturnType hal_gpio_port_toggle(uint8 port);


#endif	/* HAL_GPIO_H */

