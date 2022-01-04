/**
 * @file radix_sort.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int getMax(vector<int> input) {
    int maxElement = input[0];
    int length = input.size();

    for(int i = 1; i < length; i++) if(input[i] >= maxElement) { maxElement = input[i]; }

    return maxElement;
}

vector<int> CountingSort(vector<int> input, int exp) {
    int length = input.size();
    int index = 0;
    vector<int> count(10, 0), output(length,0);

    for(int i = 0; i < length; i++) {
        count[(input[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i++)
    count[i] += count[i-1];

    for(int i = length-1; i >= 0; i--) {
        index = (input[i]/exp)%10;
        output[count[index]-1] = input[i];
        count[index]--;
    }
    return output;
}
vector<int> RadixSort(vector<int> input) {
    vector<int> output;
    int exp = 1;

    int maxelement = getMax(input);

    for( exp = 1; maxelement/exp > 0; exp *= 10) {
        output = CountingSort(input, exp);
    }

    return output;
}

int main() {
    vector<int> input = {20, 30, 21, 1, 31, 32, 12, 23};
    auto sortedInput = RadixSort(input);
    
    for(auto x : sortedInput) {
        cout << x << endl;
    }

    return 0;
}