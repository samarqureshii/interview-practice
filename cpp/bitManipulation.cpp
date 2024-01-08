#include <iostream>
#include <string>

//How would you set, clear, and toggle a specific bit in a variable using bitwise operators?

//Given an integer variable a, write two code fragments. The first should set bit 3 of a. The second should clear bit 3 of a. In both cases, the remaining bits should be unmodified.

//Write a C++ program to encode bits in a 32-bit number such that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Then asked to generalize this to any number of bits.

//Count the number of set bits in an integer

//Bit manipulation questions - detect pattern of ones, write masks to insert pattern of ones in a 32 bit integer, swapping adjacent odd and even bits 

//Swapping Big Endian to Little Endian and vice versa

//Write a program to identify Big Endian vs Little Endian

//Bit Manipulation questions -
    //Reverse the bits of an integer
unsigned int reverseBits(unsigned int num){
    unsigned int numOfBits = sizeof(num)*8; //find the number of bits in total
    unsigned int reversed = 0; // the reversed number we are going to return
    for(int i = 0; i<numOfBits; i++){ //iterate through all the bits in the number
        //check if the i th bit in the number is "set" as 1
        if(num &  (1<<i)){
            //create bit mask  1 << ((numOfBits - 1) - i) by shifting the number 1 to the left by numOfBits - 1 - i positions and then OR it with what we want the final product to be
            reverseNum |= 1 << ((numOfBits-1)-i);
        }
    }
    
    return reverseNum;
}
    //Check the parity of a given number
    //Swap bits in a given integer(positions are provided)


//Setting and Clearing Flags:

//Given a variable, write a function that sets the nth bit to 1 and another that clears the nth bit to 0.

//Toggle Bits:
//Write a function that toggles the bits of a given variable within a specified range (e.g., bits 3 to 5).

//Creating a Bit Mask:
//Write a function that creates a bit mask where only the bits from position i to position j are set.

//Bit Extraction:
//Extract and print all the set bits in a number using bit manipulation.

//Combining Flags:
//Given two sets of flags represented as integers, write a function that combines them using bitwise OR and then filters them using bitwise AND.

//Power of Two Checker:
//Write a function that checks if a given integer is a power of two using bit manipulation.

