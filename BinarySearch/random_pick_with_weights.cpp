/**
 * @file random_pick_with_weights.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int pickRandom(vector<int> nums) {
    int sum = 0;
    vector<int> prefixSum;
    for(auto x : nums) {
        prefixSum.push_back(x + (prefixSum.empty() ? 0 : prefixSum.back()));
    }

    for(auto x : prefixSum) cout << x << "\t";
    float randNum = (float) rand() / RAND_MAX;
    cout << rand << endl;
    float target = randNum * prefixSum.back();
    cout << target << endl;

    //Need to find upper bound of target in prefixSum array
    for(int i = 0 ; i < prefixSum.size(); i++){
        if(target < prefixSum[i])
        return i;
    }

    //one liner using STL
    // return upper_bound(prefixSum.begin(), prefixSum.end(), target) - prefixSum.begin();

    return prefixSum.size()-1;
}

int main() {
    vector<int> nums = {1,2,3,4,3};
    cout << pickRandom(nums) << endl;
    return 0;
}