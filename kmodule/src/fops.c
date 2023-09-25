/**
 * @file fops.c
 * @author Sam Sui (samuelsui2002@gmail.com)
 * @brief Source file to define file operations and the kernel buffer for device file
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include "fops.h"

atomic_t already_open = ATOMIC_INIT(CDEV_NOT_USED);

size_t buffer_size = 256;
char kernel_buffer[256];

struct file_operations fops = {
    .owner      =   THIS_MODULE,
    .read       =   device_read,
    .write      =   device_write,
    .open       =   device_open,
    .release    =   device_release
};

ssize_t device_read(struct file *file, char *user_buffer, size_t len, loff_t *offs) {
    int bytes_read, not_copied;

    /* Buffer overflow check */
    bytes_read = min(len, buffer_size);

    /* Read bytes from kernel_buffer to user_buffer */
    if ((not_copied = copy_to_user(user_buffer, kernel_buffer, bytes_read)) != 0) {
        pr_warn("suimodule: %d bytes not read\n", not_copied);
    }

    return bytes_read;
}

ssize_t device_write(struct file *file, const char *user_buffer, size_t len, loff_t *offs) {
    int bytes_read, not_copied;

    /* Buffer overflow check */
    bytes_read = min(len, buffer_size);

    /* Read bytes from kernel_buffer to user_buffer */
    if ((not_copied = copy_from_user(kernel_buffer, user_buffer, bytes_read)) != 0) {
        pr_warn("suimodule: %d bytes not read\n", not_copied);
    }

    return bytes_read;
}

int device_open(struct inode *device_file, struct file *instance) {
    if (atomic_cmpxchg(&already_open, CDEV_NOT_USED, CDEV_EXCLUSIVE_OPEN)) {
        return -EBUSY;
    }
    
    try_module_get(THIS_MODULE);

    pr_info("suimodule device file successfully opened\n");
    return SUCCESS;
}

int device_release(struct inode *device_file, struct file *instance) {
    atomic_set(&already_open, CDEV_NOT_USED);

    module_put(THIS_MODULE);
    
    pr_info("suimodule device file successfully closed\n");
    return SUCCESS;
}