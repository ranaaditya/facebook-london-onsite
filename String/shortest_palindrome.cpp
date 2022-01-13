/**
 * @file shortest_palindrome.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

bool isValidPalindromeInBetween(string word, int start, int end) {
    while(start < end) {
        if(word[start] != word[end]) return false;
        else {
            start++;
            end--;
        }
    }
    return true;
}

string reverseString(string &str, int start, int end){
    reverse(str.begin() + start, str.begin()+end);

    return str;
}

string shortestPalindrome(string input) {
    string output = "";
    int ipLength = input.length();
    int i = 0;

    for(i = 0; i < ipLength; i++) {
        if(isValidPalindromeInBetween(input, 0, ipLength-1-i)){
            cout << "i: " << i << endl;
            break;
        }
    }

    if(i == ipLength) output = reverseString(input, 1, ipLength) + input; // input is non-palindromic
    else if(i == 0) output = input; // input is already palindromic
    else output = reverseString(input, ipLength-i, ipLength-1);
    return output;
}

// KMP lookup is used here
string shortestPalindromeKMP(string input) {
    string output;
    int ipLength = input.length();
    string rev(input);
    reverse(rev.begin(), rev.end());
    //cout << "rev: " << rev << "\n";
    string str = input + "#" + rev;
    int strLength = str.length();
    
    vector<int> f(strLength, 0);
    int t = 0;

    for(int i = 1; i < strLength; i++) {
        t = f[i-1];

        while(t > 0 && str[i] != str[t]) {
            t = f[t-1];
        }

        if(str[i] == str[t])
        ++t;

        f[i] = t;
    }

    output = rev.substr(0, ipLength-f[strLength-1])+input;
    return output;
}

int main() {
    string str = "aacecaaa";
    cout << shortestPalindromeKMP(str) << endl;
    return 0;
}