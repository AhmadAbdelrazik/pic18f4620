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

#include "application.h"

int main() {
    Std_ReturnType ret = E_OK;
    
    application_initialize();
    while(1) {
        
    }
    
    return (EXIT_SUCCESS);
}


Std_ReturnType application_initialize(void) {
    Std_ReturnType ret = E_OK;

    ret = ecu_layer_initialize();
    

    return ret;
};