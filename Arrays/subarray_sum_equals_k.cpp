/**
 * @file sunarray_sum_equals_k.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int numberOfSubArraySumEqualsToK(vector<int> input, int k) {
    int numOfValidSubArrays = 0;
    int start = 0, end = 0;
    int lengthOfInput = input.size();
    int currentSum = 0;

    if(lengthOfInput < 2) {
        if(input[0] == k) return 1;
        else return 0;
    }

    while(start <= end && end < lengthOfInput) {
        if(start == end) {
            if(currentSum + input[start] < k) {
            currentSum += input[start];
            end++;
            } else if( currentSum + input[end] == k) {
                numOfValidSubArrays++;
                currentSum -= input[start];
                start++;
            } else {
                start++;
                end++;
            }
            continue;
        }

    if(currentSum + input[end] < k) {
        currentSum += input[end];
        end++;
        continue;
    } else if(currentSum + input[end] == k) {
        numOfValidSubArrays++;
        currentSum -= input[start];
        start++;
        continue;
    } else if(currentSum + input[end] > k) {
        currentSum -= input[start];
        start++;
        continue;
    }
    }

    return numOfValidSubArrays;
}

int main() {
    //vector<int> input = {1,1,1};
    vector<int> input = {1,2,3};
    int k = 3;
    int output = numberOfSubArraySumEqualsToK(input, k);
    cout << output;
    return 0;
}