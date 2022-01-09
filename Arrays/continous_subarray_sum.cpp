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
        j = i+1;
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

// Trick - unordered map
bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() == 1) return false;
    unordered_map <int,int> mp;
    int sum = 0;
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
        int mod = sum % k;
        if(mod == 0 && i >= 1) return true;
        if(mp.find(mod) == mp.end()) mp[mod] = i;
        else if(mp.find(mod) != mp.end() && i - mp[mod] >= 2) return true;
    }
    return false;
}

  bool checkSubarraySumPrefixArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n);
        preSum[0] = nums[0]%k;
        for(int i = 1;i<n;i++) {
            preSum[i] = (preSum[i - 1]%k + nums[i]%k) % k;
        }
        
        unordered_map<int,int> lastInd;
        lastInd[0] = -1;
        
        for(int i = 0;i<n;i++) {
            if(lastInd.find(preSum[i]) != lastInd.end()) {
                if(i - lastInd[preSum[i]] > 1)return  true;
            } else {
                lastInd[preSum[i]] = i;
            }
        }
        return false;
    }

int main() {
    vector<int> nums = {23,2,6,4,7};
    int k = 6;
    cout << isSubarrayExist(nums, k);
    return 0;
}