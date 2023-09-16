/**
 * @file dev.h
 * @author Sam Sui
 * @brief Header file of device variables for registration
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <linux/cdev.h>
#include <linux/device.h>

dev_t dev = 0;
struct class *dev_class;
struct cdev cdev;