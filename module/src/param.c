/**
 * @file param.c
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Source file to define the handling module parameters
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include "param.h"

int pin = 2;
module_param(pin, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(pin, "An integer representing the GPIO pin to request");