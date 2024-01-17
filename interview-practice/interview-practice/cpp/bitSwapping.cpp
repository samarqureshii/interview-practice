//
//  bitSwapping.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-17.
//

//Write a C++ program to encode bits in a 32-bit number such that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Then asked to generalize this to any number of bits.

#include <stdio.h>
#include <iostream>

uint32_t bitSwap(uint32_t input){
    //isolate the 16 MSB and 16 LSB
    uint32_t upperBits = input & 0xFFFF0000;
    uint32_t lowerBits = input & 0x0000FFFF;
    uint32_t reversedUpper = 0;
    
    for(int i = 0; i < 16; i++){
        if(upperBits & (1 << (31-i))){ //if the ith bit is set,
            reversedUpper|= 1 << (15-i);
        }
    }
    
    return (reversedUpper & 0xFFFF0000) | lowerBits;
}
