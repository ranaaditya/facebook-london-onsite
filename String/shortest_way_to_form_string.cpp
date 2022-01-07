/**
 * @file shortest_way_to_form_string.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * 
 * @link https://leetcode.com/problems/shortest-way-to-form-string/
 * 
 * 
 * Problem:
 * 
 * A subsequence of a string is a new string that is formed from the original string by deleting some 
 * (can be none) of the characters without disturbing the relative positions of the remaining 
 * characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 * 
 * Given two strings source and target, return the minimum number of subsequences of source such that 
 * their concatenation equals target. If the task is impossible, return -1.
 * 
 * Example 1:
 * 
 * Input: source = "abc", target = "abcbc"
 * 
 * Output: 2
 * 
 * Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
 * 
 * 
 * Example 2:
 * 
 * Input: source = "abc", target = "acdbc"
 * 
 * Output: -1
 * 
 * Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
 * 
 * 
 * Example 3:
 * 
 * Input: source = "xyz", target = "xzyxz"
 * 
 * Output: 3
 * 
 * Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
 * 
 * Constraints:
 * 
 * 1 <= source.length, target.length <= 1000
 * 
 * source and target consist of lowercase English letters.
 * 
 */

int shortestForm(string source, string target) {
    int num = 0;

    int s = 0;
    int t = 0;

    int lenT = target.length();
    int lenS = target.length();

    while(t < lenT) {
        bool flag = false;
        s = 0;
        while(s < lenS && t < lenT) {
            if(source[s] == target[t]){
                t++;
                flag = true;
            }
            s++;
        }
        if(!flag) return -1;
        num++;
    }
    return t == lenT ? num : -1;
}
int main() {
    string source = "abc";
    string target = "abcbc";
    cout << shortestForm(source, target) << endl;
    return 0;
}