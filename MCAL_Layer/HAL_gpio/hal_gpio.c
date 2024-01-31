#include "hal_gpio.h"


// Array of addresses for TRIS registers
volatile uint8 *TRIS[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};

// Array of addresses for LAT registers
volatile uint8 *LAT[] = {&LATA, &LATB, &LATC, &LATD, &LATE};

// Array of addresses for PORT registers
volatile uint8 *PORT[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


#if GPIO_PIN_CONFIG==CONFIG_ENABLE
Std_ReturnType hal_gpio_pin_init(pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if (pin_config == NULL || pin_config->pin >= MAXIMUM_PIN_NUMBER 
            || pin_config->port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else {
        switch (pin_config->direction)
        {
            case (GPIO_OUTPUT):
                CLEAR_BIT(*TRIS[pin_config->port], pin_config->pin);
                switch (pin_config->logic){
                    case (OUTPUT_LOGIC_HIGH):
                        SET_BIT(*LAT[pin_config->port], pin_config->pin);
                        break;
                    case (OUTPUT_LOGIC_LOW):
                        CLEAR_BIT(*LAT[pin_config->port], pin_config->pin);
                        break;
                    default:
                        ret = E_NOT_OK;
                        break;
                }
                break;
            case (GPIO_INPUT):
                SET_BIT(*TRIS[pin_config->port], pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }

    return ret;
}

Std_ReturnType hal_gpio_pin_get_direction(pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if (pin_config == NULL || pin_config->pin >= MAXIMUM_PIN_NUMBER 
            || pin_config->port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else 
        pin_config->direction = READ_BIT(*TRIS[pin_config->port], pin_config->pin);

    return ret;
}


Std_ReturnType hal_gpio_pin_read(pin_config_t *pin_config, uint8 *output)
{
    Std_ReturnType ret = E_OK;
    
    if (pin_config == NULL || output == NULL 
            || pin_config->pin >= MAXIMUM_PIN_NUMBER 
            || pin_config->port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else 
        *output = READ_BIT(*PORT[pin_config->port], pin_config->pin);
    
    return ret;
}


Std_ReturnType hal_gpio_pin_write(pin_config_t *pin_config, uint8 logic)
{
    Std_ReturnType ret = E_OK;
    
    if (pin_config == NULL || pin_config->pin >= MAXIMUM_PIN_NUMBER 
            || pin_config->port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else
    {
        switch (logic) {
            case (OUTPUT_LOGIC_HIGH):
                SET_BIT(*LAT[pin_config->port], pin_config->pin);
                pin_config->logic = logic;
                break;
            case (OUTPUT_LOGIC_LOW):
                CLEAR_BIT(*LAT[pin_config->port], pin_config->pin);
                pin_config->logic = logic;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    
    return ret;
}

Std_ReturnType hal_gpio_pin_toggle(pin_config_t *pin_config)
{
    Std_ReturnType ret = E_OK;
    
    if (pin_config == NULL || pin_config->pin >= MAXIMUM_PIN_NUMBER 
            || pin_config->port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else {
        TOGGLE_BIT(*LAT[pin_config->port], pin_config->pin);
        pin_config->logic = READ_BIT(*LAT[pin_config->port], pin_config->pin);
    }
    
    return ret;
}


Std_ReturnType hal_gpio_port_init(uint8 port, uint8 direction)
{
    Std_ReturnType ret = E_OK;

    if (port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else
    {
        switch(direction) {
            case (GPIO_OUTPUT):
                *TRIS[port] = 0x00;
                break;
            case (GPIO_INPUT):
                *TRIS[port] = 0xFF;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    
    return ret;
}
#endif //GPIO_PIN_CONFIG

#if GPIO_PORT_CONFIG==CONFIG_ENABLE
Std_ReturnType hal_gpio_port_get_direction(uint8 port, uint8 *output)
{
    Std_ReturnType ret = E_OK;
    
    if (port >= MAXIMUM_PORT_NUMBER || output == NULL)
        ret = E_NOT_OK;
    else 
        *output = *TRIS[port];

    return ret;
}



Std_ReturnType hal_gpio_port_read(uint8 port, uint8 *output)
{
    Std_ReturnType ret = E_OK;
    
    if (port >= MAXIMUM_PORT_NUMBER || output == NULL)
        ret = E_NOT_OK;
    else
        *output = *PORT[port];
    
    return ret;
}
Std_ReturnType hal_gpio_port_write(uint8 port, uint8 logic)
{
    Std_ReturnType ret = E_OK;
    
    if (port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else
    {
        switch (logic)
        {
            case (OUTPUT_LOGIC_HIGH):
                *LAT[port] = 0xFF;
                break;
            case (OUTPUT_LOGIC_LOW):
                *LAT[port] = 0x00;
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    
    return ret;   
}


Std_ReturnType hal_gpio_port_toggle(uint8 port)
{
    Std_ReturnType ret = E_OK;
    
    if (port >= MAXIMUM_PORT_NUMBER)
        ret = E_NOT_OK;
    else 
       *LAT[port] ^= 0xFF;
    
    return ret;
}
#endif //GPIO_PORT_CONFIG