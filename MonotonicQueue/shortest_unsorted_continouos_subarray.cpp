/**
 * @file shortest_unsorted_continouos_subarray.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// brute force solution
// Time Complexity: O(N^2)
// Space Complexity: O(1)
int shortestUnsortedSubarrayBruteForce(vector<int> input) {
    int inputLength = input.size();
    int shortestLength = 0;
    int l = inputLength, r = 0;

    for(int i = 0; i < inputLength-1; i++)
    for(int j = i+1; j < inputLength; j++) {
        if(input[i] > input[j]) {
            l = min(l,i);
            r = max(r,j);
        }
    }
    return (r-l) < 0 ? 0 : (r-l+1);
}

// O(Nlog(N)) solution 
// if input is non negative then sort can be done using radix sort then TC = O(N)
int solutionUsingSorting(vector<int> input) {
    int length = input.size();
    auto copyInput = input;
    sort(copyInput.begin(), copyInput.end());
    int l = length, r = 0;
    for(int i = 0; i < length; i++) {
        if(input[i] != copyInput[i]) {
            l = min(i,l);
        }

        if(input[length-1-i] != copyInput[length-1-i]) {
            r = max(r,length-1-i);
        }
    }
    cout << l << "\t" << r << endl;
    return (r-l) > 0 ? (r-l+1) : 0;
}


// optimal solution 
// TimeComplexity: O(N)
// Space Somplexity: O(1)
// This solution is based on observation and visual representation of the problem
// We need to find :
// - from left: first element which breaking increasing slope sequence(ascending order) and minimum element from this element till last
// - from right: first element breaking increasing slope sequence and maximu element from this element till first element of the input array
// Then find the indices of -  first element just greater than the minimum element and first element from last just lesser than the max element so far calculated.
// answer is right - left + 1 if right >= left
int shortestUnsortedSubarray(vector<int> input) {
    int length = input.size();
    int minE = INT_MAX, maxE = INT_MIN;
    int flag = false;
    int left = -1,right = -1;
    
    for(int i = 1; i < length; i++) {
        if(input[i] < input[i-1])
        flag = true;
        
        if(flag)
        minE = min(minE, input[i]);
    }

    flag = false;

    for(int i = length-1; i > 0; i--) {
        if(input[i-1] > input[i])
        flag = true;

        if(flag)
        maxE = max(maxE, input[i-1]);
    }

    for(left = 0; left < length; left++) {
        if(input[left] > minE) break;
    }

    for(right = length-1; right > 0; right--) {
        if(input[right] < maxE) break;
    }

    return (right - left) < 0 ? 0 : (right - left +1);
}

int main() {
    vector<int> arr = {2,6,4,8,10,9,15};
    int ans = shortestUnsortedSubarray(arr);
    cout << ans << endl;
    return 0;
}