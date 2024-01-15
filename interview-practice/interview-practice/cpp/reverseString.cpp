//
//  reverseString.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-14.
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

//reverse a string in cpp
//use stack (LIFO structure)

string reverseString(string str){
    stack<char> stack;
    istringstream iss(str); //string stream that will parse in each of the chars
    string reversedString = "";
    char ch;
    
//    while(iss >> ch){ //while we can keep extracting chars
//        stack.push(ch);
//    }
    
    for(char ch: str){
        stack.push(ch);
    }
    
    //now pop each of the chars and concatenate them to the reversed string
    while(!stack.empty()){
        reversedString += stack.top();
        stack.pop();
    }
    
    return reversedString;
}

