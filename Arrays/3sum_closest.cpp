/**
 * @file 3sum_closest.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int ThreeSumClosest(vector<int> nums, int target) {
    int length = nums.size();
    int ans = INT_MIN;
    sort(nums.begin(), nums.end());
    int k = 0;
    int currentSum = 0;
    int minDiff = INT_MAX;
    int left = 0, right = length-1;

    while(left < right) {
        k = 0;
        while(k < length) {
            if(k == left || k == right) {
                k++;
                continue;
            }
            currentSum = nums[left] + nums[right] + nums[k];
            if(minDiff > abs(currentSum - target)) {
                minDiff = abs(currentSum - target);
                ans = currentSum; 
            }
            k++;
        }

        if(ans == target){
            break;
        }
        else if(ans > target){
            right--;
        } else {
            left++;
        }
    }

    return ans;

}

int main() {
    vector<int> input = {-1,2,1,-4};
    int target = 2;
    cout << ThreeSumClosest(input, target);
    return 0;
}