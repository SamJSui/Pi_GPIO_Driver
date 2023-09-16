/**
 * @file fops.h
 * @author Sam Sui
 * @brief Header file for file_operations struct implementation
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <linux/fs.h>
#include <linux/uaccess.h>

ssize_t  device_read(struct file *file, char *user_buffer, size_t count, loff_t *offs);
ssize_t  device_write(struct file *file, const char *user_buffer, size_t count, loff_t *offs);
int      device_open(struct inode *device_file, struct file *instance);
int      device_release(struct inode *device_file, struct file *instance);

struct file_operations fops = {
    .owner      =   THIS_MODULE,
    .read       =   device_read,
    .write      =   device_write,
    .open       =   device_open,
    .release    =   device_release
};