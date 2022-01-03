/**
 * @file KMP.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> computeTemporaryArray(string input) {
    int inputLength = input.length();
    vector<int> lps(inputLength, 0);

    int index = 0;

    for(int i = 1; i < inputLength;) {
        if(input[i] == input[index]) {
            lps[i] = index+1;
            index++;
            i++;
        } else {
            if(index != 0) {
                index = lps[index-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int>  KMPSearch(string text, string pattern) {
    vector<int> lps = computeTemporaryArray(pattern);
    vector<int> ans;
    int i = 0;
    int j = 0;
    int textLength = text.length();
    int patternLength = pattern.length();
    while(i < textLength && j < patternLength) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }
        if(j == patternLength) {
            //cout << "index: " << i-j << endl;
            ans.push_back(i-j);
            j = lps[j-1];
            }else if(i < textLength && pattern[j] != text[i]) {
            if(j != 0) {
                j = lps[j-1];
            }else {
                i++;
            }
        }
    }
    return ans;
}
int main() {
    string text = "foxfoxfox";
    string pattern = "fox";
    auto kmp = KMPSearch(text, pattern);
    for(auto x : kmp) {
        cout << x << "\t";
    }
    return 0;
}