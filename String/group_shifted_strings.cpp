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

string getStringHash(string str) {
    string ans = "";
    int shift = 0;

    for(int i = 1; i < str.length(); i++) {
        shift = str[i] - str[i-1];
        if(shift < 0) shift += 26;
        ans += to_string(shift);
    }

    return ans;
}

vector<vector<string>> groupShiftedStrings(vector<string> ip) {
    vector<vector<string>> ans(ip.size());
    map<string, vector<string>> hmap;
    string diff = "";

    for(auto x : ip) {
        int len = x.length();
        diff.clear();
        diff = getStringHash(x);
        cout << "DEBUG : "  << x << "\t" << diff << endl;
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