/**
 * @file ecu_keypad.c
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

#include "ecu_keypad.h"


uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMN] = {
                                                        {'7','8','9','/'},
                                                        {'4','5','6','*'},
                                                        {'1','2','3','-'},
                                                        {'#','0','=','+'}
                                                      };



Std_ReturnType ecu_keypad_initialize(const keypad_t *keypad)
{
    Std_ReturnType ret = E_OK;
    uint8 l_row_counter, l_column_counter;

    if (keypad == NULL)
        return E_NOT_OK;

    // Initialize each row pin    
    for (l_row_counter = 0; l_row_counter < ECU_KEYPAD_ROW; l_row_counter++)
        ret = hal_gpio_pin_init(&(keypad->row[l_row_counter]));

    // Initialize each column pin
    for (l_column_counter = 0; l_column_counter < ECU_KEYPAD_COLUMN; l_column_counter++)
        ret = hal_gpio_pin_init(&(keypad->column[l_column_counter]));    

    return ret;
}

Std_ReturnType ecu_keypad_get_value(const keypad_t *keypad, uint8 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 l_row_counter, l_column_counter, l_column_logic;
    
    if (keypad == NULL || value == NULL)
        return E_NOT_OK;

    
    // Write 0 on all row pins
    for (l_row_counter = 0; l_row_counter < ECU_KEYPAD_ROW; l_row_counter++)
        ret = hal_gpio_pin_write(&(keypad->row[l_row_counter]), OUTPUT_LOGIC_LOW);

    for (l_row_counter = 0; l_row_counter < ECU_KEYPAD_ROW; l_row_counter++)
    {
        // Write 1 on the current row
        ret = hal_gpio_pin_write(&(keypad->row[l_row_counter]), OUTPUT_LOGIC_HIGH);
        // write 0 on the previous row, (starting from the second row)
        if (l_row_counter > 0)
            ret = hal_gpio_pin_write(&(keypad->row[l_row_counter - 1]), OUTPUT_LOGIC_LOW);
    
        // check each column for Logic High value
        for (l_column_counter = 0; l_column_counter < ECU_KEYPAD_COLUMN; l_column_counter++)
        {
            ret = hal_gpio_pin_read(&(keypad->column[l_column_counter]), &l_column_logic);
            if (l_column_logic == OUTPUT_LOGIC_HIGH)
            {
                *value = btn_values[l_row_counter][l_column_counter];
                return ret;
            }
        }

    }

    *value = 0;

    return ret;
}