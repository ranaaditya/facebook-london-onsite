/**
 * @file one_edit_distance.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<bits/stdc++.h>
using namespace std;

bool isOneEditDistanceStrings(string s, string t) {
    map<char, int> charSet;
    int numOfRemovalChars = 0, numOfInsertionChars = 0;
    for(auto ch : t) {
        charSet[ch]++;
    }

    for(auto y : s) {
        charSet[y]--;
    }

    for(auto x : charSet) {
        if(x.second < 0) numOfRemovalChars--;
        else if (x.second > 0) numOfInsertionChars++;
    }

    if ( (numOfRemovalChars == -1 && numOfRemovalChars == 0) || (numOfRemovalChars == 0 && numOfInsertionChars == +1) || (numOfRemovalChars == -1 && numOfInsertionChars == +1)) return true;
    return false;
}
int main() {
    string s = "";
    string t = "";
    cout << isOneEditDistanceStrings(s,t);
    return 0;
}