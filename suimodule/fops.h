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

#ifndef SUIMODULE_FOPS_H
#define SUIMODULE_FOPS_H

#include "atomic.h"
#include "macros.h"

#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>

static size_t buffer_size = 256;
static char *kernel_buffer;

/**
 * @brief Reads data out of the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
static ssize_t device_read(struct file *file, char *user_buffer, size_t count, loff_t *offs) {
    int bytes_read, not_copied;

    /* Buffer overflow check */
    bytes_read = min(count, buffer_size);

    /* Read bytes from kernel_buffer to user_buffer */
    if ((not_copied = copy_to_user(user_buffer, kernel_buffer, buffer_size)) != 0) {
        pr_warn("suimodule: %d bytes not read\n", not_copied);
    }

    return bytes_read;
}

/**
 * @brief Writes data to the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
static ssize_t device_write(struct file *file, const char *user_buffer, size_t len, loff_t *offs) {
    int bytes_read, not_copied;

    /* Buffer overflow check */
    bytes_read = min(len, buffer_size);

    /* Read bytes from kernel_buffer to user_buffer */
    if ((not_copied = copy_from_user(kernel_buffer, user_buffer, len)) != 0) {
        pr_warn("suimodule: %d bytes not read\n", not_copied);
    }

    return bytes_read;
}

/**
 * @brief Function is called when device file is opened
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
static int device_open(struct inode *device_file, struct file *instance) {
    if (atomic_cmpxchg(&already_open, CDEV_NOT_USED, CDEV_EXCLUSIVE_OPEN)) {
        return -EBUSY;
    }
    
    try_module_get(THIS_MODULE);

    pr_info("suimodule device file successfully opened\n");
    return SUCCESS;
}

/**
 * @brief Function is called when device file is closed
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
static int device_release(struct inode *device_file, struct file *instance) {
    atomic_set(&already_open, CDEV_NOT_USED);

    module_put(THIS_MODULE);
    
    pr_info("suimodule device file successfully closed\n");
    return SUCCESS;
}

static struct file_operations fops = {
    .owner      =   THIS_MODULE,
    .read       =   device_read,
    .write      =   device_write,
    .open       =   device_open,
    .release    =   device_release
};

#endif // SUIMODULE_FOPS_H