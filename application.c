/**
 * @file application.c
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

/********* Section : Includes ************/

#include "application.h"

/********* Section : Externed Global variables ************/



/********* Section : Main function ************/

int main() {
    Std_ReturnType ret = E_OK;
    application_initialize();
    
    // Super Loop
    while(1) {
        
    }
    
    return (EXIT_SUCCESS);
}

/********* Section : Initialization Function ************/

Std_ReturnType application_initialize(void) {
    Std_ReturnType ret = E_OK;
    ret = ecu_layer_initialize();
    return ret;
};