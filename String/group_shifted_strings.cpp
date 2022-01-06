/**
 * @file group_shifted_strings.cpp
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

vector<vector<string>> groupShiftedStrings(vector<string> ip) {
    vector<vector<string>> ans(ip.size());
    map<string, vector<string>> hmap;
    string diff = "";

    for(auto x : ip) {
        int len = x.length();
        diff.clear();
        
        for(int i = 1; i < len; i++) {
            diff += to_string(abs(x[i-1]-x[i]));
        }
        cout << "DEBUG : " << diff << endl;
        hmap[diff].push_back(x);
    }

    int i = 0;

    for(auto  y : hmap) {
        int l = ans[i].size();
        ans[i].insert(ans[i].begin()+l, y.second.begin(), y.second.end());
        i++;
    }

    return ans;
}

int main() {
    vector<string> ip = {"abc","bcd","acef","xyz","az","ba","a","z"};
    auto output = groupShiftedStrings(ip);

    for(auto x : output) {
        for(auto h : x)
        cout << h << "\t";

        cout << endl;
    }

    return 0;
}