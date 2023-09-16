/**
 * @file init.h
 * @author Sam Sui
 * @brief Header file to store the function prototypes of init.c
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <linux/module.h>
#include <linux/init.h>

/**
 * @brief Constructor to initialize kernel module
 * 
 * @return int 
 */
static int __init sui_module_init(void);

/**
 * @brief Destructor to de-allocate resources
 * 
 */
static void __exit sui_module_exit(void);