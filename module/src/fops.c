/**
 * @file fops.c
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Source file to define file operations and the kernel buffer for device file
 * @version 0.1
 * @date 2023-09-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #include "fops.h"

atomic_t already_open = ATOMIC_INIT(CDEV_NOT_USED);

size_t buffer_size = 20;
char kernel_buffer[20];

struct file_operations fops = {
    .owner      =   THIS_MODULE,
    .read       =   device_read,
    .write      =   device_write,
    .open       =   device_open,
    .release    =   device_release
};

ssize_t device_read(struct file *file, char *user_buffer, size_t len, loff_t *offs) {
    int not_copied, bytes_read;
    uint8_t pin_state;

    /* Read bytes from kernel_buffer to user_buffer */
    bytes_read = min(len, buffer_size);

    pin_state = gpio_get_value(pin);

    sprintf(kernel_buffer, "%d", (int)pin_state);

    pr_info("sui_gpio: device read %s\n", kernel_buffer);
    if ((not_copied = copy_to_user(user_buffer, kernel_buffer, buffer_size)) != 0) {
        pr_warn("sui_gpio: %d bytes not read\n", not_copied);
    }

    return bytes_read;
}

ssize_t device_write(struct file *file, const char *user_buffer, size_t len, loff_t *offs) {
    int not_copied;

    /* Clear the buffer */
    memset(kernel_buffer, '\0', buffer_size);

    /* Read bytes from kernel_buffer to user_buffer */
    if ((not_copied = copy_from_user(kernel_buffer, user_buffer, len)) > 0) {
        pr_warn("sui_gpio: %d bytes not read\n", not_copied);
    }

    /* Set GPIO Pin */
    if (kernel_buffer[0] == '1') {
        gpio_set_value(pin, 1);
    }
    else if (kernel_buffer[0] == '0') {
        gpio_set_value(pin, 0);
    }
    else {
        pr_err("sui_gpio: unknown device file write value - provide GPIO with 1/0\n");
    }

    pr_info("sui_gpio: device write %s", kernel_buffer);

    return len;
}

int device_open(struct inode *device_file, struct file *instance) {
    if (atomic_cmpxchg(&already_open, CDEV_NOT_USED, CDEV_EXCLUSIVE_OPEN)) {
        return -EBUSY;
    }
    
    try_module_get(THIS_MODULE);

    pr_info("sui_gpio: device file successfully opened\n");
    return SUCCESS;
}

int device_release(struct inode *device_file, struct file *instance) {
    atomic_set(&already_open, CDEV_NOT_USED);

    module_put(THIS_MODULE);
    
    pr_info("sui_gpio: device file successfully closed\n");
    return SUCCESS;
}