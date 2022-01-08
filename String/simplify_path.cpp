/**
 * @file simplify_path.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string input) {
    string ans;
    int length = input.length();

    stack<char> st;

    for(int i = 0 ; i < length; i++) {
        cout << "DEBUG MODE: \t" << "input[" << i+1 << "]" << " " << input[i] << endl;
        if(input[i] == '.') continue;
        if(!st.empty()) {
            if(st.top() == '/' && input[i] == '/') {
                continue;
            }
            else {
                st.push(input[i]);
                cout << "input  : " << input[i] << endl;
            }
        }
    }
    ans.clear();
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string str = "/path/";
cout << simplifyPath(str) << endl;

    return 0;
}