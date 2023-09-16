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

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

static int  __init suimodule_init(void);
static void __exit suimodule_exit(void);