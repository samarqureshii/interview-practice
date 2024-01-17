//
//  evenOddBitSwap.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-17.
//

#include <stdio.h>
#include <iostream>
#include <sstream>

//Given an unsigned integer N. The task is to swap all odd bits with adjacent even bits.


unsigned int swapEvenOddBits(unsigned int N){
    for(int i = 0; i < sizeof(N); i+=2){
        //swap bits at ith and i+2th index 
        int currBit = 1 & (N >> i); //find the ith bit instead of checking if the 1th bit is set which we would do with (N & (1 << i))
        int nextBit = 1 & (N >> (i+1));
        
        //now swap them
        
        //remove the currbit and remove the next bit
        N = N - 
        
        
    }
    return N;
}
