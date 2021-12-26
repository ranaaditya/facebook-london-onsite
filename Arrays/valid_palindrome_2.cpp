/**
 * @file valid_palindrome_2.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Problem:
 * 
 * Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * 
 * Test Cases:
 * 
 * #1:
 * Input: s = "aba"
 * Output: true
 * 
 * #2:
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * #3:
 * Input: s = "abc"
 * Output: false
 * 
 * Constraints:
 * - 1 <= s.length <= 105
 * - s consists of lowercase English letters.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// solution using Map
bool validpalindrome(string input)  {
    map<char, int> charSet;
    int numOfRemovals = 0;
    for(auto x : input) {
        charSet[x]++;
}
    for(auto ch : charSet) {
        if(ch.second < 2) { numOfRemovals++; }
    }

    if(numOfRemovals > 2) return false;
    return true;
}



int main() {
    string input = "abca";
    cout << validpalindrome(input);
    return 0;
}