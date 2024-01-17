//
//  reverseLinkedList.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-16.
//

#include <stdio.h>
#include <sstream>
#include <vector>
#include <thread>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    
    while(curr!=nullptr){
        next = curr->next; //temp
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev; //new head of the list
}
