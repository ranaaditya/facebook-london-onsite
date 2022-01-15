/**
 * @file shortest_subarray_with_sum_atleast_k.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * We will use prefix sumarray and then traverse it and hold a Increasing Monotonic Queue and on each insert 
 * we will check if inserting is smaller that means we have a window of elements that have increasing sum but first 
 * we will check if the last element is greater then the required sum `k` then we will start decreasing elements from 
 * front of the queue till the sum of the window is still holding the condition of greater then the required `k`. 
 * We will stop this process when the sum of the window is less than the `k`, just calculate the size of the window by 
 * doing j-i+1, where `i` is the starting index of the window and `j` is the ending index of the window. Repeat this process 
 * till the end of the prefix array.
 * 
 * @param input 
 * @param targetSum 
 * @return int 
 */
int shortestSubarrayWithSumAtleastK(vector<int> input, int targetSum) {
    int inputLength = input.size();
    int leastSum = inputLength+1;
    deque<int> monoque;

    vector<int> prefixSum(inputLength+1, 0);
    prefixSum[0] = input[0];

    for(int i = 0; i < inputLength; i++)
    prefixSum[i+1] = prefixSum[i] + input[i];

    //for(auto f : prefixSum) cout << f << "\t";

    int prefixSumLength = prefixSum.size();

    for(int i = 0; i < prefixSumLength; i++) {

        while(!monoque.empty() && prefixSum[i] <= prefixSum[monoque.back()])
            monoque.pop_back();

        while(!monoque.empty() && prefixSum[i] - prefixSum[monoque.front()] >= targetSum) {
            leastSum = min(leastSum, i-monoque.front());
            // cout << "ls: " << leastSum << endl;
            monoque.pop_front();
        }

        monoque.push_back(i);        
    }

    return leastSum < inputLength+1 ? leastSum : -1;
}

int main() {
    //vector<int> arr = {2,-1,2};
    vector<int> arr = {70,-50,50,50,-70,-10,30,20,30,20};
    cout << shortestSubarrayWithSumAtleastK(arr, 100) << endl;
    return 0;
}