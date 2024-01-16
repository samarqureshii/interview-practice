////
////  binarySearch.cpp
////  interview-practice
////
////  Created by Samar Qureshi on 2024-01-14.
////
//
//#include <stdio.h>
//
////binary search
////Problem: Given a sorted array of integers nums and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
//using namespace std;
//
//int binarySearch(const vector<int>& nums, int target){
//    //keep track of left and right indices;
//    int left = 0;
//    int right = nums.size() - 1;
//
//    while(left <= right){
//        int mid = (left + (right-left))/2;
//        if(target > nums[mid]){ //target is in the upper half
//            left = mid + 1;
//        }
//        
//        else if(target < nums[mid]){ //arget is in the lower half
//            right = mid - 1;
//        }
//        
//        else{ //target is the mid
//            return mid;
//        }
//
//    }
//    
//    return -1;
//}
