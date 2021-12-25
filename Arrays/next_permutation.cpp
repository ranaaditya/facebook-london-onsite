/**
 * @file next_permutation.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).
 * The replacement must be in place and use only constant extra memory.
 * 
 * Test Cases:
 * 
 * #1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * 
 * #2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * 
 * #3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * 
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& input) {
    int length = input.size();
    int index = length-2, index_reverse = length-2;
    
    for(index = length-2; index >=0; index--)
        if(input[index] < input[index+1]) break;

    if(index < 0) { sort(input.begin(), input.end()); return input; } // this is the case when array is sorted in descending order and no next permutation is there !
    
    for( index_reverse = length-2; index_reverse >= 0; index_reverse--)
        if(input[index_reverse] > input[index]) break;

    swap(input[index], input[index_reverse]);
    reverse(input.begin() + index+1, input.end());
    return input;
}

int main() {
    vector<int> input = {1,3,5,4,2};
    //vector<int> input = {3,2,1};
    auto output = nextPermutation(input);
    for(auto x : output) cout << x;
    return 0;
}