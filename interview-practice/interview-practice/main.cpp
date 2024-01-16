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
#include <memory> //smart pointer 

using namespace std;

//reverse a linkedlist

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head) { //feed the head in
    //head becomes the tail
    if(head == nullptr){
        return nullptr;
    }
   
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr; //temp
    
    while(curr!=nullptr){
        //iterate through each
        next = curr->next; //temp node
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int main() {
    // Example usage
    // List creation and testing the function can be done here
}

