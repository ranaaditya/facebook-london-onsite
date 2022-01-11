/**
 * @file randomizer.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int randomizer(int low, int high) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(low, high);

    return distribution(generator);
}

float randomizer (float low, float high) {
    random_device rd;
    default_random_engine dre(rd());
    uniform_real_distribution<float> uid(low, high);

    return (float) uid(dre);
}

double randomizer(double low, double high){
    random_device rd;
    default_random_engine dre(rd());
    uniform_real_distribution<double> uid(low, high);

    return (float) uid(dre);
}

char randomizer(char low, char high) {
    int shiftLow = low - 'a';
    int shiftHigh = high - 'a';

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(shiftLow, shiftHigh);

    return distribution(generator) + 'a';

}

int main() {
    double start = 0.00;
    double end = 10.00;

    char low = 'a';
    char high = 'z';

    for(int i = 0; i < 5; i++){
        cout << randomizer(low, high) << endl;
    }

    return 0;
}