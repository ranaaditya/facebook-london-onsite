/**
 * @file median_two_sorted_arryas.cpp
 * @author https://github.com/ranaaditya
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * Test case 1:
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Test Case 2:
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// 2-pointer algo
int medianTwoSorted_twopointer(vector<int> first, vector<int> second) {
    int n = first.size();
    int m = second.size();
    int half = (n + m)/2;
    bool isDoubletRequired = false;

    if(half%2 != 0) isDoubletRequired = true;

    int i = 0, j = 0;

    while((i+j) < half-1) {
        if(first[i] <= second[j]) {
            if(i < n) i++; else j++;
        }
        else {
            if(j < m) j++; else i++;
        }
    }

    if(!isDoubletRequired) { return first[i] < second[j] ? first[i]: second[j];}

    int l ,r;
    if(first[i] < second[j]) { l = first[i]; i++; } else { l = second[j]; j++; }
    if(first[i] < second[j]) { r = first[i]; i++; } else { r = second[j]; j++; }
    return (l+r)/2;
}

// optimal solution using binary-search
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; 
            
        
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; 
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; 
            
            
            if(left1 <= right2 && left2 <= right1) {
                if( (n1 + n2) % 2 == 0 ) 
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }

int main() {
    vector<int> first = {1,3,4,7,10,12};
    vector<int> second = {2,3,6,15};
    cout << findMedianSortedArrays(first, second);
    return 0;
}