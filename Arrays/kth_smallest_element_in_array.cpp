/**
 * @file kth_smallest_element_in_array.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int LomutoPartition(vector<int>& ip, int low, int high) {
    int pivot = ip[high];
    int i = low;

    for(int j = low; j < high; j++){
        if(ip[j] < pivot){
            if(i != j) {
                swap(ip[i], ip[j]);
            }
            i++;
        }
    }
    swap(ip[i], ip[high]);
    return i;
}

int HoaresPartition(vector<int> v, int left, int right) {
    return -1;
}

int KthSmallest(vector<int> input, int left, int right, int k) {
    if(left == right)
    return input[left];

    int pivotIndex = LomutoPartition(input, left, right);

    if(k-1 == pivotIndex)
    return input[pivotIndex];

    else if(pivotIndex > k-1){
        right = pivotIndex-1;
    }

    else {
        left = pivotIndex+1;
    }

    return KthSmallest(input, left, right, k);
}
int main() {
    vector<int> ip = {7,-2,5,8,1,6};
    int i = LomutoPartition(ip, 0, 5);
    for(auto x : ip)
    cout << x << "\t";

    cout << endl <<  "pivot index : " << i << endl;

    cout << KthSmallest(ip, 0,5,2);
    return 0;
}