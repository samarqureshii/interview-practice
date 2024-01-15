//
//  slidingWindow.cpp
//  interview-practice
//
//  Created by Samar Qureshi on 2024-01-14.
//

#include <stdio.h>
//Problem: Given an array of positive integers nums and an integer k, find the maximum sum of any contiguous subarray of size k. Write a function that returns this maximum sum.

int slidingWindow(int nums[], int size, int k){
    int sum = 0;
    int max = 0;
    //search for contiguous subarrays of size k
    for(int i = 0; i<size; i++){ //to traverse throughout the entire array
        for(int j = i; j<=k; j++){ //to traverse at every "window"
            sum+=nums[j];
            if(sum>max){
                max = sum;
            }
        }
        sum = 0;
        
    }
    return max;
}
