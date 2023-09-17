/**
 * @file driver.h
 * @author Sam Sui
 * @brief Header file of driver code for the suimodule Linux kernel module 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SUIMODULE_DRIVER_H
#define SUIMODULE_DRIVER_H

#include "dev.h"
#include "fops.h"
#include "macros.h"

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

/**
 * @brief Constructor to initialize kernel module
 * 
 * @return int 
 */
static int  __init suimodule_init(void);

/**
 * @brief Destructor to de-allocate resources
 * 
 */
static void __exit suimodule_exit(void);

#endif // SUIMODULE_DRIVER_H