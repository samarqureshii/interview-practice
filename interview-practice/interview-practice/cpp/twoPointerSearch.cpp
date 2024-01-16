//
//  twoPointerSearch.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-14.
//

#include <stdio.h>

//Problem: You are given an array of integers nums and an integer target. Write a function to find if there exist two numbers in nums such that they add up to target. Your function should return true if such a pair exists and false otherwise.

//bool twoPointerSearch(int nums[], int target){
//    for(int i = 0; nums[i]!=NULL; i++){
//        for(int j = 0; nums[j]!=NULL; j++){
//            if(nums[i] + nums[j] == target){
//                return true;
//            }
//        }
//    }
//    return false;
//}

bool twoPointerSearch(int nums[], int size, int target){ //assume nums is sorted already
    int left = 0; //left index
    int right = size -1; //right index
    while(left <= right){
        int sum = nums[left] + nums[right];
        if(target < sum){
            right --;
        }
        
        else if(target > sum){
            left ++;
        }
        else{
            return true;
        }
    }
    
    return false;
}

