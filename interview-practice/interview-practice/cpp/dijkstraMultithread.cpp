//
//  dijkstraMultithread.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-13.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <random>

using namespace std;

//Dijkstra Producer Consumer problem

class BoundedBuffer{
private:
    size_t capacity;
    int itemCount;
    mutex mtx; //so we can manage the capacity resource between the producer and consumer thread (synchronized access mutex)
    queue<int> buffer;
    bool bufferFull;
public:
    BoundedBuffer(size_t n){
        capacity = n;
        itemCount = 0;
    }
    
    
    void addItem(int item){ //add an item to the buffer
        unique_lock<mutex> lock(mtx); //lock the mutex
        while(itemCount >= capacity){
            //wait until the consumer thread has emptied out some of the queue
            //this is not efficient for the CPU, so this thread can sleep for a bit
            mtx.unlock();
            this_thread::sleep_for(chrono::seconds(1)); //sleep for 1s
            mtx.lock();
        }
        
        //once the item count is less than the capacity of the bounded buffer, we can add the item to it
        buffer.push(item);
        itemCount++;
    }
    
    int removeItem(){ //remove the first item from the buffer (queues are FIFO)
        unique_lock<mutex> lock(mtx); //lock the mutex
        while(itemCount <= 0){ //we can't remove anything from the queue until there is something to remove
            mtx.unlock();
            this_thread::sleep_for(chrono::seconds(1)); //more efficient for the CPU
            mtx.lock();
        }
        int removed = buffer.front();
        buffer.pop();
        itemCount--;
        
        return removed;
        
        
    }
    
    
};

void producerWorker(BoundedBuffer& buf){
    //generate random numbers and put it in the queue
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,100);
    //random number generation here
    buf.addItem(distrib(gen));
    
}

void consumerWorker(BoundedBuffer& buf){
    cout << "consumed: " << buf.removeItem() << endl;
}


int mainDijkstra(){
    BoundedBuffer buffer(10);
    
    thread producer(producerWorker, ref(buffer));
    thread consumer(consumerWorker, ref(buffer));
    
    producer.join();
    consumer.join();
    
    return 0;
}



