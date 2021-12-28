/**
 * @file comparators.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// if a > b then returns true and it swapping will happen in the sorting function. That's ascending sorting my boi !
bool comparator(int a, int b) {
    cout << "executing the comaparator: \t" << "a: " << a << "\t" << "b: " << b << endl;
    return a > b;
}

void bubble_sort(vector<int>& input, bool (&cmp) (int a, int b)) {
    int length = input.size();
    for(int i = 0; i < length-1; i++)
    for(int j = 0; j < length - i - 1; j++) {
        if(cmp(input[j], input[j+1])) {
            swap(input[j], input[j+1]);
        }
    }
}

int main() {
    vector<int> input = {5,4,3,2,1};
    bubble_sort(input, comparator);

    for(auto x : input) cout << x << " ";
    return 0;
}