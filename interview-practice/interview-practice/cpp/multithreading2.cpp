//
//  multithreading2.cpp
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

using namespace std;
static bool s_Finished = false;

void DoWork(){

    while(!s_Finished){
        cout << "working..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int working(){
    thread worker(DoWork); //pass in function and its arguments
    cin.get();
    s_Finished = true;
    worker.join(); //main thread will wait until worker thread has finished
    
    return 0;
}
