/**
 * @file param.h
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Header file to declare variables for holding module parameters
 * @version 0.1
 * @date 2023-09-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SUI_PARAM_H
#define _SUI_PARAM_H

#include <linux/module.h>
#include <linux/moduleparam.h>

/**
 * @brief Number of values in the GPIO pins array which will read in
 * 
 */
extern int num_pins_in;

/**
 * @brief Number of values in the GPIO pins array which will read out
 * 
 */
extern int num_pins_out;

/**
 * @brief Integer array to hold which GPIO pins to request input
 *
 */
extern int in[28];

/**
 * @brief Integer array to hold which GPIO pins to request output
 * 
 */
extern int out[28];

#endif // _SUI_PARAM_H