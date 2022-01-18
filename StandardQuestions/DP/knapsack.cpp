/**
 * @file knapsack.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int knapsk[1024][1024];

int knapsack(vector<int> weight, vector<int> value, int capacity, int size) {
    if(size == 0 || capacity == 0)
    return 0;

    if(weight[size-1] <= capacity) {
        return max((value[size-1] + knapsack(weight, value, capacity - weight[size-1], size-1)), knapsack(weight, value, capacity, size-1));
    }

    //else if(weight[size] > capacity)
    return knapsack(weight, value, capacity, size-1);
}

int knapsackMemoization(vector<int> weight, vector<int> value, int capacity, int size) {
    if(size == 0 || capacity == 0)
    return 0;

    if(knapsk[size][capacity] != -1) 
    return knapsk[size][capacity];

    if(weight[size-1] <= capacity) {
        return knapsk[size][capacity] = max((value[size-1] + knapsackMemoization(weight, value, capacity - weight[size-1], size-1)), knapsackMemoization(weight, value, capacity, size-1));
    }

    //else if(weight[size] > capacity)
    return knapsk[size][capacity] = knapsackMemoization(weight, value, capacity, size-1);
}

int dp[1024][1024];

int knapsackDP(vector<int> weight, vector<int> value, int capacity, int size) {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= size; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }

    for(int i = 1; i <= size; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weight[i] <= capacity)
                dp[i][j] = max((value[i-1] + dp[i-1][j-weight[i-1]]), dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    //   for(int i = 0; i <= size; i++){
    //     for(int j = 0; j <= capacity; j++)
    //         cout << dp[i][j] << "\t";
        
    //     cout << endl;
    // }
    
    
    return dp[size][capacity];
}

int main() {
    vector<int> weight = {1,2,3,4,5};
    vector<int> value = {5,2,3,4,5};
    int capacity = 8;
    int size = 5;

    cout << knapsack(weight, value, capacity, size) << endl;

    memset(knapsk, -1, sizeof(knapsk));

    cout << knapsackMemoization(weight, value, capacity, size) << endl;

    cout << knapsackDP(weight, value, capacity, size);

    return 0;
}