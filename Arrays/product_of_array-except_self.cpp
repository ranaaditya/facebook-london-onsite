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

#include<bits/stdc++.h>
using namespace std;

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