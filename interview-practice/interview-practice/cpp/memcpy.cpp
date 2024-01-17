//
//  memcpy.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-17.
//

#include <stdio.h>
#include <iostream>

//void *memcpy(void *to, const void *from, size_t numBytes);

//to: A pointer to the memory location where the copied data will be stored.
//from: A pointer to the memory location from where the data is to be copied.
//numBytes: The number of bytes to be copied.

//implement a custom memcpy


void *memcpy(void *dest, const void *src, size_t numBytes) {
    // Cast src and dest to char* for byte-wise copying
    char *charDest = static_cast<char*>(dest);
    const char *charSrc = static_cast<const char*>(src);

    // Copy each byte
    for (size_t i = 0; i < numBytes; ++i) {
        charDest[i] = charSrc[i];
    }

    // Return the original destination pointer
    return dest;
}
