/* 
 * File:   main.c
 * Author: Ahmed Abdelrazik
 *
 * Created on January 11, 2024, 2:13 PM
 */

#include "main.h"

Std_ReturnType ret = E_OK;

int main() {
    ret = hal_gpio_port_init(PORTC_INDEX, GPIO_OUTPUT);
    ret = hal_gpio_port_write(PORTC_INDEX, OUTPUT_LOGIC_HIGH);

    while(1)
    {
        ret = hal_gpio_port_write(PORTC_INDEX, OUTPUT_LOGIC_HIGH);
        __delay_ms(200);
        ret = hal_gpio_port_write(PORTC_INDEX, OUTPUT_LOGIC_LOW);
        __delay_ms(200);
    }
    return (EXIT_SUCCESS);
}

