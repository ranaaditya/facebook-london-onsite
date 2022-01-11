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

/**
 * Problem:
 * 
 * You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
 * 
 * You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).
 * 
 * For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 * 
 * TestCases:
 * 
 * #1:
 * 
 * Input: ["Solution","pickIndex"]
 * 
 * [[[1]],[]]
 * 
 * Output: [null,0]
 * 
 * Explanation:
 * 
 * Solution solution = new Solution([1]);
 * 
 * solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
 * 
 * #2:
 * 
 * Input: ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
 * 
 * [[[1,3]],[],[],[],[],[]]
 * 
 * Output: [null,1,1,1,1,0]
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