//
//  main.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-07.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <random>
#include <atomic>
#include <stack>

using namespace std;

//varint decoder... again

vector<uint32_t> decode_varint(vector<uint8_t>& input){
    vector<uint32_t> output;
    int curr = 0;
    int shift = 0;
    
    for(uint8_t byte : input){ //iterate through every 8 bit byte in the input
        //if the MSB in the byte is set
        if(byte & 0x80){
            //then extract the 7 MSB and append to the current varint
            curr|= static_cast<uint32_t>(byte & 0x7F) << shift;
            shift+=7;
            
            if(shift == 28 && (byte & 0xF0)){ //at this point, we have gone through 4 bytes and are on the 5th one. we can only extract 4 more meaningful bits of data from the fifth byte. anything beyond this would indicate overflow. we can check this by seeing if the 4 <Sb in the final byte are set or not
                return vector<uint32_t>(); //return empty vector
            }
        }
        //if the MSB in the byte is not set, we are at the last byte
        else{
            //finish off the current varint
            curr|= static_cast<uint32_t>(byte & 0x7F) << shift;
            //and append it to the output vector
            output.push_back(curr);
            //and reset these for the next varint in the input
            shift = 0;
            curr = 0;
            
        }
        //check for an incomplete varint
        if(!input.empty() && (input.back() & 0x80)){
            return vector<uint32_t>();
        }
        
        return output;
    }
    

    
    
    return output;
}

