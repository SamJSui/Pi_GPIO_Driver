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
 * @brief Number of values in the pins array
 * Unintuitive naming for command line flag
 */
extern int num_pins;

/**
 * @brief Integer array to hold which GPIO pins to request
 * Unintuitive naming for command line flag
 */
extern int p[28];

#endif // _SUI_PARAM_H