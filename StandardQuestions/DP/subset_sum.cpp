/**
 * @file subset_sum.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

bool dp[1024][1024];

void printDP(int x, int y) {
    for(int i = 0; i <= x; i++){ 
        for(int j = 0; j <= y; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
     }
}

int subset_sum(vector<int> input, int targetSum, int size) {
    for(int i = 1; i <= targetSum; i++)
        dp[0][i] = false;
    for(int i = 0; i <= size; i++)
        dp[i][0] = true;

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= targetSum; j++) {
            if(input[i-1] <= j) {
                dp[i][j] = (dp[i-1][j-input[i-1]] || dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //printDP(size, targetSum);    
    return dp[size][targetSum];
}

int main() {
    vector<int> arr = {2,3,5,7,8,1};
    memset(dp, false, sizeof(dp));
    cout << subset_sum(arr, 10, 6) << endl;
    return 0;
}