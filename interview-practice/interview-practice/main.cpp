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

using namespace std;

class BankAccount {
    // ... Class implementation
    public:
    int balance;
    mutex mtx; //synchronized access mutex
    
    BankAccount(){ //constructor
        balance = 0;
    }
    
    void deposit(int val){
        lock_guard<mutex> lock(mtx); //lock the mutex
        balance+=val;
    }
    
    bool withdraw(int val){
        lock_guard<mutex> lock(mtx); //lock the mutex
        //return true if we can withdraw the balance, return false if the balance is so low that we cannot withdraw anything from it
        if(balance - val >=0){
            balance-=val;
            return true;
        }
        else{ // we cannot return any balance
            return false;
        }
    }
    
};

void bankingOperation(BankAccount& account, int depositAmount, int withdrawAmount) {
    account.deposit(depositAmount);
    if (!account.withdraw(withdrawAmount)) { //if we cannot withdraw bc we are broke
        cout << "Failed to withdraw: " << withdrawAmount << endl;
    }
}


int main() {
    // Create BankAccount object
    BankAccount account;

    // Create and start threads
    thread t1(bankingOperation, ref(account), 500, 100);
    

    // Join threads

    // Print final balance
    return 0;
}




