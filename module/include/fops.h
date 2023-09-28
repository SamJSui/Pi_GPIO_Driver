/**
 * @file fops.h
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Header file for file_operations struct implementation
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SUI_FOPS_H
#define _SUI_FOPS_H

#include "atomic.h"
#include "gpio.h"
#include "macros.h"

#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/uaccess.h>

extern size_t buffer_size;
extern char kernel_buffer[20];

extern struct file_operations fops;

/**
 * @brief Reads data out of the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
extern ssize_t device_read(struct file *file, char *user_buffer, size_t len, loff_t *offs);

/**
 * @brief Writes data to the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
extern ssize_t device_write(struct file *file, const char *user_buffer, size_t len, loff_t *offs);

/**
 * @brief Function is called when device file is opened
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
extern int device_open(struct inode *device_file, struct file *instance);

/**
 * @brief Function is called when device file is closed
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
extern int device_release(struct inode *device_file, struct file *instance);

#endif // _SUI_FOPS_H