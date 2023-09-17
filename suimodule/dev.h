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

#ifndef SUIMODULE_DEV_H
#define SUIMODULE_DEV_H

#include <linux/cdev.h>
#include <linux/device.h>

static dev_t dev;
static struct class *dev_class;
static struct cdev cdev;

#endif // SUIMODULE_DEV_H