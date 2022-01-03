/**
 * @file Z_Algorithm.cpp
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

vector<int> calculateZArray(string input) {
    int inputLength = input.length();
    //cout << "length: " << inputLength;
    vector<int> Z(inputLength, 0);
    int left = 0;
    int right = 0;

    for(int k = 1; k < inputLength; k++) {
        if(k > right) {
            left = right = k;
            while(right < inputLength && input[right] == input[right-left]) {
                right++;
            }
            Z[k] = right - left;
            right--;
        }
        else {
            int k1 = k - left;
            if(Z[k1] < right - k +1) {
                Z[k] = Z[k1];
            }
            else {
                left = k;
                while(right < inputLength && input[right] == input[right-left]) {
                right++;
            }
            Z[k] = right - left;
            right--;
            }
        }
    }
    // for(auto x : Z)
    // cout << x << "\t";
    return Z;
}

vector<int> ZPatternMatching(string text, string pattern) {
    int patternLength = pattern.length();
    string input = pattern + "$" + text;

    vector<int> ZArray = calculateZArray(input);
    int ZArrayLength = ZArray.size();
    vector<int> ZIndices;

    for(int index = 0; index < ZArrayLength; index++) {
        if(ZArray[index] == patternLength) ZIndices.push_back(index - patternLength - 1);
    }
    return ZIndices;
}

int main() {
    string text = "foxfoxfox";
    string pattern = "fox";
    auto Z = ZPatternMatching(text, pattern);
    for(auto x : Z)
    cout << x << endl;
    return 0;
}