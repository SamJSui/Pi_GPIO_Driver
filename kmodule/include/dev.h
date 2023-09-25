/**
 * @file dev.h
 * @author Sam Sui (samuelsui2002@gmail.com)
 * @brief Header file of device variables for registration
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SUI_DEV_H
#define _SUI_DEV_H

#include <linux/cdev.h>
#include <linux/device.h>

static dev_t dev;
static struct class *dev_class;
static struct cdev cdev;

#endif // _SUI_DEV_H