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

int HoaresPartition(vector<int> ip, int low, int high) {
    int pivot = ip[low];
    int i = low-1;
    int j = high+1;
    
    while(true) {
        do{
            i++;
        }while(ip[i] < pivot);

        do{
            j--;
        }while(ip[j] > pivot);

        if(i >= j){
            return j;
        }

        swap(ip[i], ip[j]);
    }
    return -1;
}

int KthSmallestLomutoPartitioning(vector<int> input, int left, int right, int k) {
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

    return KthSmallestLomutoPartitioning(input, left, right, k);
}

int KthSmallestHoaresPartitioning(vector<int> input, int left, int right, int k) {
    if(left == right)
    return input[left];

    int pivotIndex = HoaresPartition(input, left, right);

    if(k == pivotIndex)
    return input[pivotIndex];

    else if(pivotIndex > k){
        right = pivotIndex-1;
    }

    else {
        left = pivotIndex+1;
    }

    return KthSmallestHoaresPartitioning(input, left, right, k);
}


int main() {
    vector<int> ip = {7,-2,5,8,1,6};

    cout << KthSmallestLomutoPartitioning(ip, 0,5,2) << endl;
    cout << KthSmallestHoaresPartitioning(ip,0,5,2) << endl;
    return 0;
}