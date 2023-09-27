/**
 * @file atomic.h
 * @author Sam Sui (ssui at vols dot utk dot edu)
 * @brief Header file to handle concurrent operations on the same file
 * @version 0.1
 * @date 2023-09-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SUI_ATOMIC_H
#define _SUI_ATOMIC_H

#include <linux/atomic.h>

enum {
    CDEV_NOT_USED = 0,
    CDEV_EXCLUSIVE_OPEN = 1,
};

extern atomic_t already_open;

#endif // _SUI_ATOMIC_H