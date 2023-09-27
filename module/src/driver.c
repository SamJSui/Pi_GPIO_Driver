/**
 * @file driver.c
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Source file of the module code for the suimodule Linux kernel module 
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "driver.h"

static int __init sui_driver_init(void) {
    int i;

    /* Allocate device major number */
    if ((alloc_chrdev_region(&dev, 0, 1, DRIVER_NAME)) < 0) {
        pr_err("sui_gpio: cannot allocate device major number\n");
        return ERROR;
    }
    pr_info("sui_gpio: device number: major=%d minor=%d\n", MAJOR(dev), MINOR(dev));

    /* Create cdev struct */
    cdev_init(&cdev, &fops);

    if ((cdev_add(&cdev, dev, 1)) < 0) {
        pr_err("sui_gpio: character device could not be added\n");
        return ERROR;
    }

    /* Device class creation */
    #if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
        if ((dev_class = class_create(CLASS_NAME)) == NULL) {
            pr_err("sui_gpio: module cannot create the struct class\n");
            goto error_class;
        }
    #else
        if ((dev_class = class_create(THIS_MODULE, CLASS_NAME)) == NULL) {
            pr_err("sui_gpio: module cannot create the struct class\n");
            goto error_class;
        }
    #endif

    /* Creating device */
    if (device_create(dev_class, NULL, dev, NULL, DEVICE_NAME) == NULL) {
        pr_err("sui_gpio: module cannot create the Device 1\n");
        goto error_device;
    }

    strcpy(kernel_buffer, "sui_gpio: kernel buffer");

    /* Count valid elements of module parameter p */
    for (i = 0; i < 28; i++) {
        if (p[i] == 0) {
            break;
        }
        num_pins++;
    }

    /* Pretty prints which pins were read by the module parameters */
    pr_info("sui_gpio: %d pins: ", num_pins);
    for (i = 0; i < num_pins; i++) {
        printk(KERN_CONT "%d ", p[i]);
    }

    /* Greaaat successs :) */
    pr_info("sui_gpio: module successfully loaded\n");
    return SUCCESS;

    /* Error labels */
    error_device:
        class_destroy(dev_class);
    error_class:
        cdev_del(&cdev);
        unregister_chrdev_region(dev, 1);
        return ERROR;
}

static void __exit sui_driver_exit(void) {
    device_destroy(dev_class, dev);
    class_destroy(dev_class);
    cdev_del(&cdev);
    unregister_chrdev_region(dev, 1);
    pr_info("sui_gpio: module successfully removed\n");
}

module_init(sui_driver_init);
module_exit(sui_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sam Sui (ssui at vols dot utk dot edu)");
MODULE_DESCRIPTION("Linux kernel module that allocates a character device driver to buffer data on physical memory.");
MODULE_VERSION("0.1");