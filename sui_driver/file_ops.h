/**
 * @file file_ops.h
 * @author Sam Sui
 * @brief Header file for device file operations
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DRIVER_NAME "sui_driver"
#define DRIVER_CLASS "sui_driver_class"

/**
 * @brief Buffer for holding data
 * 
 */
extern static char buffer[255];
extern static int buffer_pointer;

/**
 * @brief Function is called when device file is opened
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
static int driver_open(struct inode *device_file, struct file *instance);

/**
 * @brief Function is called when device file is closed
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
static int driver_close(struct inode *device_file, struct file *instance);

/**
 * @brief Reads data out of the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
static ssize_t driver_read(struct file *file, char *user_buffer, size_t count, loff_t *offs);

/**
 * @brief Writes data to the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
static ssize_t driver_write(struct file *file, const char *user_buffer, size_t count, loff_t *offs);

 static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write
};