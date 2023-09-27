/**
 * @file macros.h
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Header file to hold project macros
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SUI_MACROS_H
#define _SUI_MACROS_H

#include <linux/err.h>
#include <linux/printk.h>

/* Returns */
#define SUCCESS 0
#define ERROR -1

/* Device */
#define CLASS_NAME  "sui_gpio"
#define DRIVER_NAME "sui_gpio"
#define DEVICE_NAME "sui_gpio"

#endif // _SUI_MACROS_H