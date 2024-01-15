//
//  varintDecoder.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-11.
//

#include <stdio.h>
#include <iostream>
using namespace std;


vector<uint32_t> decode_varint(vector<uint8_t>& input){ //pass input by reference
    int shift = 0;
    int curr = 0;
    vector <uint32_t> output; //the output that we will return
    
    //loop over each byte in the input vector
    for(uint8_t byte : input){
        //check the continuation (8th) bit
        if(byte & 0x80){
            //extract the 7 LSB (8th bit is used as a continuation flag)
            //combine the current value with the bits from the byte
            curr|= static_cast<uint32_t>(byte & 0x7F) << shift;
            shift+=7;
            
            //overflow check here
            if(shift > 28 && !(byte & 0xF0)){ //on the fifth byte is where we could have potential overflow
                //we can concatenate a fifth byte, but only the LSB 4 bits, anything more would mean overflow
                shift = 0;
                curr = 0;
                return vector<uint32_t>();
            }

        }
        
        else{ //the continuation bit is not set, we are at a byte like 0xxxxxxx which is the last byte of the varint
            //append curr to the output
            curr|= static_cast<uint32_t>(byte & 0x7F) << shift;
            output.push_back(curr);
            curr = 0;
            shift = 0;
            
            
        }
    }
    
    //did the input end on a case where there is more data we just couldn't fit it in 32 bits,
    if(!input.empty() && (input.back() & 0x80)){
        return vector<uint32_t>();
    }
    
    return output;
}
