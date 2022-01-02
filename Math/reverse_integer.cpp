/**
 * @file reverse_integer.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * @link https://leetcode.com/problems/reverse-integer/
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int reverseIntegre(int input) {
    int output = 0;
    if(input == INT_MAX || input == INT_MIN) { return 0; }

    while(input) {
        output *= 10;
        output += input % 10;
        input /= 10;
    }

    return output;
}

int main() {
    cout << reverseIntegre(123456789);
    return 0;
}