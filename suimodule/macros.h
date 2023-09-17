/**
 * @file macros.h
 * @author Sam Sui
 * @brief Header file to hold project macros
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <linux/err.h>
#include <linux/printk.h>

/* Returns */
#define SUCCESS 0
#define ERROR -1

/* Device */
#define CLASS_NAME  "suiclass"
#define DRIVER_NAME "suidriver"
#define DEVICE_NAME "suidev"