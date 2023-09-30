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
 * @brief Integer corresponding to which GPIO pin to request
 * 
 */
extern int pin;

#endif // _SUI_PARAM_H