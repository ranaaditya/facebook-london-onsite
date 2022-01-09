/**
 * @file continous_subarray_sum.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
 * 
 * An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 * 
 * TestCases:
 * 
 * #1:
 * 
 * Input: nums = [23,2,4,6,7], k = 6
 * 
 * Output: true
 * 
 * Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
 * 
 * #2:
 * 
 * Input: nums = [23,2,6,4,7], k = 6
 * 
 * Output: true
 * 
 * Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
 * 42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
 * 
 * #3:
 * 
 * Input: nums = [23,2,6,4,7], k = 13
 * 
 * Output: false
 * 
 */
#include<bits/stdc++.h>
using namespace std;

bool isSubarrayExist(vector<int> nums, int k) {
    bool hasSubArray = false;
    int i = 0, j = 0;
    int length = nums.size();
    int currentSum = 0;

    while(i < length && j < length) {
        currentSum = nums[i];
        if( i == j) {
            j++;
        }
        while(j < length) {
        currentSum += nums[j];
        if(currentSum % k == 0 && (j-i) > 0) {
            cout << "i = " << i << "\nj = " << j << endl;
            return true;
        }
        j++;
        }
        i++;
    }
    return hasSubArray;
}

int main() {
    vector<int> nums = {23,2,6,4,7};
    int k = 6;
    cout << isSubarrayExist(nums, k);
    return 0;
}