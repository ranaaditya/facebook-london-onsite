/**
 * @file naive.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int naivePatternSearch(string input, string pattern) {
    int index = -1;
    int m = input.length();
    int n = pattern.length();
    
    for(int i = 0; i < m-n+1; i++) {
        for(int j = 0; j < n; j++) {
            if(j == n-1) return i;
            else if(input[j+i] != pattern[j]) break;
            else continue;
        }
    }
    return index;
}

int main() {
    string input = "roxfoxfox";
    string pattern = "fox";
    cout << naivePatternSearch(input, pattern);
    return 0;
}
