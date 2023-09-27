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

int num_pins = 0;

int p[28] = {8};
module_param_array(p, int, NULL, 0);
MODULE_PARM_DESC(p, "Array of integers corresponding to which GPIO pins to request access to");