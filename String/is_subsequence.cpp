/**
 * @file is_subsequence.cpp
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

 bool isSubsequence(string s, string t) {
        if(s.length() == t.length()) {
            return s == t;
        }

        int i = 0;
        int l = s.length();
        
        for(auto x : t) {
            if(s[i] == x) i++;
            
            if(i == l) return true;
        }
        
        return false;
    }

int main() {
    string s = "acy";
    string t = "axcdy";
    cout << isSubsequence(s,t) << endl;
    return 0;
}