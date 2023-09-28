/**
 * @file driver.h
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Header file of driver code for the suimodule Linux kernel module 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUI_DRIVER_H
#define SUI_DRIVER_H

#include "dev.h"
#include "fops.h"
#include "gpio.h"
#include "macros.h"
#include "param.h"

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

/**
 * @brief Constructor to initialize kernel module
 * 
 * @return int 
 */
static int  __init sui_driver_init(void);

/**
 * @brief Destructor to de-allocate resources
 * 
 */
static void __exit sui_driver_exit(void);

#endif // SUI_DRIVER_H