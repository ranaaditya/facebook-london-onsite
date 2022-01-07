/**
 * @file container_with_most_water.cpp
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

int mostWater(vector<int> container) {
    int length = container.size();
    int ans = INT_MIN;
    for(int i = 0; i < length; i++) {
        for( int j = i+1; j < length; j++) {
            ans = max(ans, (j-i)*min(container[i], container[j]));
        }
    }
    return ans;
}

int main() {

    vector<int> container = {1,8,6,2,5,4,8,3,7};
    cout << mostWater(container) << endl;
    return 0;
}