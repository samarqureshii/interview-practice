//
//  varintDecoder.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-11.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//Varints are variable-length unsigned integers where an integer can take up 1 or more bytes

//each byte in a varint, except for the last byte, has the most significant bit (MSB) set- this indicates that further bytes follow
//the lower 7 bits of each byte store the bits of the number, in groups of seven
//the least significant group comes first (the first 7 lower bits decsribe the 7 least significant bits of the output number
//each decoded value must fit in a 32 bit unsigned integer, and the input stream of data must completely encode valid integers
//if a decoded value would overflow a 32-bit integer, or if the last byte indicates there is more data but there are no more elements to parse, the entire result should return an empty vector

vector<uint32_t> decode_varint(vector<uint8_t>& input){ //pass input by reference
    int shift = 0; //the amount will will shift input by so we can iterate through each of the bytes
    int curr = 0;
    vector <uint32_t> output; //the output that we will return
    
    //should we assume that the input will be 32 bits or less? T
    
    for(uint8_t byte : input){ //iterate through each 8 bit byte in the varint
        if(byte){ //if the input exceeds 32 bits,
            
            shift = 0;
        }
    }
    //bit mask to xtract the lower 7 bits will be 10000000
    
    //concatenate the bits using OR
    //output |= static_cast<uint32_t>
    
    
    //if decoded value overflows 32 bit integer, then we should return an empty vector
    
    //check if the output vector is empty before trying to append the current byte in the varint
    if(!output.empty()){
        output.push_back(curr);
    }
    
    return output;
}
