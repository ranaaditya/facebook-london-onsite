/**
 * @file remove_duplicates_from_sorted_array.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**

* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
* each unique element appears only once. The relative order of the elements should be kept the same.

* Since it is impossible to change the length of the array in some languages, you must instead have the
* result be placed in the first part of the array nums. More formally, if there are k elements after removing
* the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

* Return "k" after placing the final result in the first k slots of nums.

* Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

* Test Cases:

* #1
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

* #2
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

 */

/**
 * Edge cases:
 * #1:
 * when array is empty
 * 
 * #2:
 * when array has just one element
 * 
 * #3:
 * when all elements of array are distinct -> this will become the WORST CASE SCENARIO with Time Complexity TC = O(n)
 * 
 * #4:
 * when all elements of the array are same -> TC = O(n)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// input array is already sorted in non-descending(ascending) order.
int removeDuplicates(vector<int>& input) {

    if(input.size() == 0) return 0;
    if(input.size() == 1) return 1;

    int i = 0, j = 0, k = 0;
    int length = input.size();

    while(i < length) {
        j = i;
        for(j = i+1; j < length; j++) {
            if(input[j] == input[i]) { continue; }
            else break;
        }
        input[k] = input[i];
        k++;
        i = j; 
    }

    //debuging input
    // for(auto x : input) {
    //     cout << x;
    // }

    return k;
}

// STL hack
int removeDuplicatesHack(vector<int>& nums) {
    nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
    nums.shrink_to_fit();
    return nums.size();

     //return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
}

int main() {
    //vector<int> input = {1,1,2};
    vector<int> input = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(input) << endl;
 //   cout << removeDuplicatesHack(input);
    return 0;
}