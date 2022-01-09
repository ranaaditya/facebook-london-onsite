/**
 * @file pow.cpp
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

double power(double x, unsigned int n) {
    double ans;
    if(n == 0) {
        return 1;
    }
    ans = power(x, n/2);
    if(n % 2 == 0)
    return ans*ans;
    else return x*ans*ans;
}

int main() {
    cout << power(2,5);
    return 0;
}