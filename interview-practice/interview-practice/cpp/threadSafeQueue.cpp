//
//  threadSafeQueue.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-16.
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
private:
    vector<int> queueArray; //automatically handle memory allocation/size management
    size_t head;
    size_t tail;
    size_t elements;
    size_t capacity;
    mutex mtx;
public:
    threadSafeQueue(int s){ //constructor
        capacity = s;
        head = 0;
        tail = 0;
        elements = 0;

    }
    
    ~threadSafeQueue(){ //destructor
        
    }
    
    void push(int item){
        //Inserts an item at the end of the queue.
        lock_guard<mutex> lock(mtx); //how to lock the mutex?
        
        //The queue should expand its capacity when it runs out of space by allocating a new array that is double the size, copying over the existing elements, and then deallocating the old array.
        
        if(elements >= queueArray.size()){ // if we are at capacity, allocate a new array that is double the size and then copy the elements over
            queueArray.resize(queueArray.size()*2);
        }
        
        //add the new item to the back of the queue
        queueArray.push_back(item);
        
    }
    
    int pop(){
        // Removes an item from the front of the queue and returns it.
        lock_guard<mutex> lock(mtx);
        return queueArray.front();
    }
    
    size_t size(){ //returns the number of elements in the queue;
        lock_guard<mutex> lock(mtx);
        return elements;
    }
};
