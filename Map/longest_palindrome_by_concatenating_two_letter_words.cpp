/**
 * @file longest_palindrome_by_concatenating_two_letter_words.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(vector<string> words) {
    map<string, int> wordmap;
    int palindromeLength = 0;
    bool reached = false;
    for(auto w : words)
        wordmap[w]++;
    
    for(auto x : wordmap) {
        if(x.first[0] == x.first[1]) {
            if(x.second % 2 && !reached) {
                reached = true;
                palindromeLength += 2*x.second;
                x.second = 0;
            } else if(x.second%2 == 0) {
                palindromeLength += 2*x.second;
                x.second = 0;
            }
        } else {
            string temp = x.first;
            reverse(temp.begin(), temp.end());
            if(wordmap.find(temp) != wordmap.end()) {
                int m = min(wordmap[temp], x.second);
                palindromeLength += m*4;
                x.second -= m;
                wordmap[temp] -= m; 
            }
        }
    }
    return palindromeLength;
}

int main() {
    vector<string> words = {"cc","ll","xx"};
    cout << longestPalindrome(words) << endl;
    return 0;
}