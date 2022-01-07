/**
 * @file number_of_matching_subsequences.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * @link https://leetcode.com/problems/number-of-matching-subsequences/
 * 
 * Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
 * 
 * A subsequence of a string is a new string generated from the original string with some characters 
 * (can be none) deleted without changing the relative order of the remaining characters.
 * 
 * Test Cases:
 * 
 * #1:
 * 
 * Input: s = "abcde", words = ["a","bb","acd","ace"]
 * 
 * Output: 3
 * 
 * Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
 * 
 * 
 * #2:
 * 
 * Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
 * 
 * Output: 2
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int NumberOfMatchingSubseq(string S, vector<string>& words) {
    vector<const char*> waiting[128];
    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str());

//    for(auto x: waiting) {
//         for(auto y : x)
//         cout << y << " ";

//         cout << endl;
//     }

    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size();
}

int main() {
    vector<string> input = {"a","bb","acd","ace"};
    string s = "abcde";
    int output = NumberOfMatchingSubseq(s, input);
    cout << output << endl;
    return 0;
}