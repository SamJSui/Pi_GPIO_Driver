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
    int i, j;

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

    /* Count valid elements of module param array in */
    i = num_pins_in;

    /* Count valid elements of module param array in */
    j = num_pins_out;

    /* Pretty prints which pins were read by the module parameters */
    pr_info("sui_gpio: %d pins in: ", num_pins_in);
    for (i = 0; i < num_pins_in; i++) {

        if (gpio_is_valid(in[i]) == false) {
            pr_err("GPIO %d is not valid\n", in[i]);
            goto error_gpio; 
        }
        sprintf(kernel_buffer, "GPIO_%d", in[i]);
        if(gpio_request(in[i], kernel_buffer) < 0){
            pr_err("ERROR: GPIO %d request\n", in[i]);
            goto error_gpio;
        }
        gpio_direction_output(in[i], 0);
        gpio_export(in[i], false);
        printk(KERN_CONT "%d ", in[i]);

    }
    printk(KERN_CONT "\n");

    pr_info("sui_gpio: %d pins out: ", num_pins_out);
    for (j = 0; j < num_pins_out; j++) {

        if (gpio_is_valid(out[j]) == false) {
            pr_err("GPIO %d is not valid\n", out[j]);
            goto error_gpio; 
        }

        sprintf(kernel_buffer, "GPIO_%d", out[j]);
        
        if(gpio_request(out[j], kernel_buffer) < 0){
            pr_err("ERROR: GPIO %d request\n", out[j]);
            goto error_gpio;
        }

        gpio_direction_input(out[j]);
        gpio_export(out[j], false);
        printk(KERN_CONT "%d ", out[j]);
    }
    printk(KERN_CONT "\n");

    /* Greaaat successs :) */
    pr_info("sui_gpio: module successfully loaded\n");
    return SUCCESS;

    /* Error labels */
    error_gpio:
        for (; i < num_pins_in; i++) {
            gpio_free(in[i]);
        }
        for (; j < num_pins_out; j++) {
            gpio_free(out[j]);
        }
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