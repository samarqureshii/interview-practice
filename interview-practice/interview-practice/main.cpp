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
#include <vector>

using namespace std;

//You are required to implement a thread-safe queue in C++ that will be used in a high-performance application where multiple threads will be pushing and popping items concurrently. The queue should be dynamically allocated and should have the capability to expand if more items are added than its initial size.
class threadSafeQueue{
public:
    int elements;
    threadSafeQueue(int s){ //constructor
        mutex mtx;
        elements = s;
        new arr[size];
    }
    
    ~threadSafeQueue(){ //destructor
        delete[];
    }
    
    void push(int item){
        //Inserts an item at the end of the queue.
        lock_guard<mutex> lock(mtx); //how to lock the mutex?
        
        //The queue should expand its capacity when it runs out of space by allocating a new array that is double the size, copying over the existing elements, and then deallocating the old array.

        
    }
    
    int pop(){
        // Removes an item from the front of the queue and returns it.
        lock_guard<mutex> lock(mtx);
    }
    
    size_t size(){ //returns the number of elements in the queue;
        lock_guard<mutex> lock(mtx);
        return elements;
    }
};

int main(){
    threadSafeQueue queue;
}

