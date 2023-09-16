/**
 * @file driver.c
 * @author Sam Sui
 * @brief Source file of driver code for the suimodule Linux kernel module 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dev.h"
#include "driver.h"
#include "fops.h"
#include "macros.h"

/**
 * @brief Constructor to initialize kernel module
 * 
 * @return int 
 */
static int __init suimodule_init(void) {

    /* Allocate device major number */
    if ((alloc_chrdev_region(&dev, 0, 1, DRIVER_NAME)) < 0) {
        pr_err("Cannot allocate device major number\n");
        return 1;
    }
    pr_info("suimodule device numbers: Major=%d Minor=%d\n", MAJOR(dev), MINOR(dev));

    /* Device class creation */
    #if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
        dev_class = class_create(DEVICE_NAME);
    #else
        dev_class = class_create(THIS_MODULE, DEVICE_NAME);
    #endif
    device_create(dev_class, NULL, MKDEV(MAJOR(dev), 0), NULL, DEVICE_NAME);

    /* Create cdev struct */
    cdev_init(&cdev, &fops);

    pr_info("suimodule successfully loaded\n");
    return 0;
}

/**
 * @brief Destructor to de-allocate resources
 * 
 */
static void __exit suimodule_exit(void) {

    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("suimodule successfully removed\n");

}

module_init(suimodule_init);
module_exit(suimodule_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam Sui");
MODULE_DESCRIPTION("");
MODULE_VERSION("0.1");