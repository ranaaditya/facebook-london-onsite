/**
 * @file minimum_remove_make_valid_parantheses.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * @link https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * 
 * Given a string s of '(' , ')' and lowercase English characters.
 * 
 * Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
 * 
 * Formally, a parentheses string is valid if and only if:
 * 
 * It is the empty string, contains only lowercase characters, or
 * 
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * 
 * It can be written as (A), where A is a valid string.
 * 
 * Test Cases:
 * 
 * 
 * #1:
 * 
 * Input: s = "lee(t(c)o)de)"
 * 
 * Output: "lee(t(c)o)de"
 * 
 * Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
 * 
 * #2:
 * 
 * Input: s = "a)b(c)d"
 * 
 * Output: "ab(c)d"
 * 
 */

#include<bits/stdc++.h>
using namespace std;

string makeValidString(string& str) {
    string ans;
    int len = str.length();
    stack<int> st;

    for(int i = 0; i < len; i++) {
        if(str[i] == '(') st.push(i);
        if(str[i] == ')'){
            if(!st.empty())st.pop();
            else {
                str.erase(i,1);
                len--;
                i--;
                continue;
            }
        }
    }

    if(!st.empty()) {
        int fact=0;
        while(!st.empty()) {
            int indx = st.top();
            st.pop();
            str.erase(str.begin()+indx+fact);
            fact++;
        }
    }
    return str;
}

int main() {
    string input = "a)b(c)d";
    string ip = "lee(t(c)o)de)";
    cout << makeValidString(input) << endl;
    cout << makeValidString(ip) << endl;
    return 0;
}