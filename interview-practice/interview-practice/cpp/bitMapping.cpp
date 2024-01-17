//
//  bitMapping.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-16.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <chrono>

//Write a function that takes in a 32-bit integer as input and outputs a 32-bit integer. The function will map the input to output with the condition that every single bit in the input corresponds to 2 bits in the output.

uint32_t bitMap(uint32_t input){
    uint32_t output = 0;
    
    //for every set bit, we get two set bits
    //for every non set bit, we get one bit
    
    //we can only look at the first 16 bits of the input
    for(int i = 0; i< 16; i++){
        if(input & (1 << i)){ //is the ith bit set?
            //multiply i by 2 and set that position bit in the output
            output|= 3 << (i*2); //3 in binary is 11
        }
    }
    
    return output;
}
