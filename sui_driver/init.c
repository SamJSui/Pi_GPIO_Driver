/**
 * @file init.c
 * @author Sam Sui
 * @brief Driver source file for the sui_driver kernel module
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "init.h"

static int __init sui_module_init(void) {
    
    printk("sui_driver successfully loaded\n");

    return 0; // Init function returned successfully
}

static void __exit sui_module_exit(void) {

    printk("sui_driver successfully removed\n");

}

module_init(sui_module_init);
module_exit(sui_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam Sui");
MODULE_DESCRIPTION("");
MODULE_VERSION("0.1");