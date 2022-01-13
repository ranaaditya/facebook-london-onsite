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

int main() {
    string str = "baaa";
    cout << shortestPalindrome(str) << endl;
    return 0;
}