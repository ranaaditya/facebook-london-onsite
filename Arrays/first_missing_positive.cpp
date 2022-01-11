/**
 * @file first_missing_positive.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**
 * Problem:
 * 
 * Given an unsorted integer array nums, return the smallest missing positive integer.
 * 
 * You must implement an algorithm that runs in O(n) time and uses constant extra space.
 * 
 * #1:
 * 
 * Input: nums = [1,2,0]
 * 
 * Output: 3
 * 
 * #2:
 * 
 * Input: nums = [3,4,-1,1]
 * 
 * Output: 2
 * 
 * #3:
 * 
 * Input: nums = [7,8,9,11,12]
 * 
 * Output: 1
 * 
 */
#include<bits/stdc++.h>
using namespace std;

pair<int, int> getMax(vector<int> ip) {
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(auto x : ip){
        if(x < 0) continue;
        if(x >= mx) mx = x;
        else if(x <= mn) mn = x;
    }
    return {mn, mx};
}

int firstMissingPositive(vector<int> input) {
    int length = input.size();

    auto minMaxPair = getMax(input);
    map<int, int> hmap;

    for(int i = (minMaxPair.first > 0 ? 1 : 0); i <= minMaxPair.second; i++) {
        hmap[i] = 0;
    }

    for(auto x : input) {
        if(x < 0) continue;

        hmap[x]++;
    }

    for(auto k : hmap) {
        if(k.second == 0) return k.first;
    }

    // if no element is found then return maximum + 1 (acc to question)
    return minMaxPair.second+1;
}
int main() {

    vector<int> arr = {3,4,-1,1};
    cout << firstMissingPositive(arr) << endl;
    return 0;
}