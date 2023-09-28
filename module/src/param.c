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

int num_pins_in = 1;
module_param(num_pins_in, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(in, "Number of input pins to request");

int num_pins_out = 1;
module_param(num_pins_out, int, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(in, "Number of output pins to request");

int in[28] = {2};
module_param_array(in, int, NULL, 0);
MODULE_PARM_DESC(in, "Array of integers corresponding to which input pins to request access to");

int out[28] = {3};
module_param_array(out, int, NULL, 0);
MODULE_PARM_DESC(out, "Array of integers corresponding to which output pins to request access to");