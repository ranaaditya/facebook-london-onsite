/**
 * @file equal_sum_partition.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

bool dp[100][100];

void printDP(int x, int y) {
    for(int i = 0; i <= x; i++){ 
        for(int j = 0; j <= y; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
     }
}

bool isEqualSumpartitionPossible(vector<int> arr) {
    int sum = 0;
    int size = arr.size();
    sum = accumulate(arr.begin(), arr.end(), sum);

    // odd sum can never be subdivided into two equal integer parts
    if(sum%2 !=0) return false;

    for(int i = 0; i <= size; i++)
        dp[0][i] = false;
    for(int i = 0; i <= sum/2; i++)
        dp[i][0] = true;

    for(int i = 1; i<= size; i++) {
        for(int j = 1; j <= sum/2; j++) {
            if(arr[i-1] <= j)
            dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            else
            dp[i][j] = dp[i-1][j];
        }
    }

    //printDP(size, sum/2);
    return dp[size][sum/2];
}

int main() {
    memset(dp, false, sizeof(dp));
    vector<int> arr = {2,4,6,8,10,10};
    cout << isEqualSumpartitionPossible(arr) << endl;
    return 0;
}