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

// comparator for lower_bound
bool lb_comparator(int a, int b) {
    return a <= b;
}

int main() {
    vector<int> input = {5,4,3,2,1};
    bubble_sort(input, comparator);
    for(auto x : input) cout << x << " ";


    // we can use comparators to reverse the logic of the lower_bound() as well !
    vector<int> money = {10,20,30,40,50,60,70,80,90};
    int key = 55;
    // lower_bound() gives ">=" comparison"
    // so here output will be 60
    int lb_index = lower_bound(money.begin(), money.end(), key) - money.begin();
    cout << endl <<  money[lb_index] << endl;
    
    int lb_modified_index = lower_bound(money.begin(), money.end(), key, lb_comparator) - money.begin();
    cout << "Modified search via lower_bound" << endl <<  money[lb_modified_index] << endl;
    return 0;
}