/**
 * @file fops.c
 * @author Sam Sui
 * @brief Source file for file_operations struct implementation
 * @version 0.1
 * @date 2023-09-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "fops.h"
#include "macros.h"

/**
 * @brief Reads data out of the given buffer
 * 
 * @param file 
 * @param user_buffer 
 * @param count 
 * @param offs 
 * @return ssize_t 
 */
ssize_t device_read(struct file *file, char *user_buffer, size_t count, loff_t *offs) {

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
ssize_t device_write(struct file *file, const char *user_buffer, size_t count, loff_t *offs) {

}

/**
 * @brief Function is called when device file is opened
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
int device_open(struct inode *device_file, struct file *instance) {
    pr_info("suimodule device file opened\n");
    return SUCCESS;
}

/**
 * @brief Function is called when device file is closed
 * 
 * @param device_file 
 * @param instance 
 * @return int 
 */
int device_release(struct inode *device_file, struct file *instance) {
    pr_info("suimodule device file opened\n");
    return SUCCESS;
}