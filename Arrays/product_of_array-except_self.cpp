/**
 * @file product_of_array-except_self.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Problem:
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * Test Cases:
 * 
 * #1:
 * 
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * #2:
 * 
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * One pass solution.
 * 
 * Simply find how many zeroes are there in the input array.
 * 
 * If only one zero is there then all outputs will be zero except the zeroth index itself, it would be the product of all elements of input except the zero itself.
 * 
 * If more than one zero is there then all elements of the output will be zero
 * 
 * 
 * Complexity Analysis:
 * 
 * Time Complexity : O(N); N = length of input
 * 
 * Space Complexity : O(N); output is fresh new array; we can also make this to O(1) by modifying the input array itself
 * 
 * @param input 
 * @return vector<int> 
 */
vector<int> productOfArrayExceptSelf(vector<int>& input) {
    int inputLength = input.size();
    vector<int> output(inputLength, 0), zeroIndex;
    int numOfZeroes = 0;
    long long int cummulativeProduct = 1;
    int index = 0;

    for(index = 0; index < inputLength; index++) {  
        int x = input[index];
        if(x != 0) {
            cummulativeProduct *= x;
        } else { 
            numOfZeroes++;
            zeroIndex.push_back(index);
         }
     }

     if(numOfZeroes == 0 || numOfZeroes > 1) {
         for(auto y : input) {
             y = cummulativeProduct/y;
         }
     } else if(numOfZeroes == 1) {
         output[zeroIndex[0]] = cummulativeProduct;
     }

    return output;
}
int main() {
    vector<int> input = {-1,1,0,-3,3};
    auto output = productOfArrayExceptSelf(input);
    for(auto x : output) cout << x << " ";
    return 0;
}