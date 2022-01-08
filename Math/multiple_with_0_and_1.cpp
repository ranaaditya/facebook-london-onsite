/**
 * @file multiple_with_0_and_1.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. 
 * Since this multiple could be large, return it in form of a string.
 * 
 * TestCase:
 * 
 * #1:
 * Input: n = 3
 * 
 * Output: 111
 * 
 * #2:
 * 
 * Input: n = 18
 * 
 * @param n 
 * @return string 
 */
// string smallestMultipleWithZeroAndOne(int n) {
//     string output = "1";
//     string outputL = "1", outputR = "1";
//     string left, right;
//     long long unsigned int leftLL, rightLL;
//     while(true) {
//         left.clear(); right.clear();
//         left = outputL + "0";
//         right = outputR + "1";
//         leftLL = atoi(left.c_str());
//         rightLL = atoi(right.c_str());

//         cout << "DEBUG: \t" << "LEFT: " << leftLL << endl;
//         cout << "DEBUG: \t" << "RIGHT: " << rightLL << endl;

//         if(rightLL % n == 0) {
//             output = right;
//             break;
//         }
//         else if(leftLL % n == 0) {
//             output = left;
//             break;
//         }
//         outputL = left;
//         outputR = right;
//     }
//     return output;
// }

string multiple(int A) {
    queue<pair<string, int>> q; // {string, mod A}
    q.push({"1",1%A});
    vector<bool> ss(A+1, 0);
    ss[1] = 1;
    while(!q.empty()){
        if(q.front().second == 0)
            return q.front().first;
        int nextmod1 = (10*(q.front().second))%A;
        int nextmod2 = (nextmod1 + 1)%A;
        if(ss[nextmod1] == 0){
            q.front().first.push_back('0');
            q.push({q.front().first, nextmod1});
            ss[nextmod1] = 1;
            q.front().first.pop_back();
        }
        if(ss[nextmod2] == 0){
            q.front().first.push_back('1');
            q.push({q.front().first, nextmod2});
            ss[nextmod2] = 1;
        }
        q.pop();
    }
    return "-1";
}

int main() {
    int n = 12;
    cout << multiple(n) <<  endl;
    return 0;
}