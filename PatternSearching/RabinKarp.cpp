/**
 * @file RabinKarp.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

long long calculateHash(string text, int start, int end, int prime) {
    long long hash;

    for(int i = start; i <= end; i++) {
        hash += text[i]*pow(prime, i);
    }
    return hash;
}

long long reCalculateHash(string text, long long oldHash, int start, int end, int prime) {
    long long rehash;
    rehash = ((oldHash - text[start-1])/prime) + (text[end]*pow(prime, end-start));
    return rehash;
}

int RabinKarpSearch(string input, string pattern) {
    int inputLength = input.length();
    int patternLength = pattern.length();
    int prime = 3;
    long long patternHash = calculateHash(pattern, 0, patternLength-1, prime);
    long long inputHash = calculateHash(input, 0, patternLength-1, prime);

    for(int i = 0; i < inputLength-patternLength+1; i++) {
        if(patternHash == inputHash) {
            bool ok = true;
            for(int k = 0; k < patternLength; k++) {
                if(pattern[k] != input[k+i]) {ok = false; break;}
            }
            if(ok) cout << i << endl;
        }
        if(i < inputLength-patternLength+1) {
            inputHash = reCalculateHash(input, inputHash, i+1, i + patternLength -1, prime);
            //inputHash = calculateHash(input, i+1, i+patternLength, prime);
            cout << inputHash << "\t";
        }
    }
    return -1;
}

int main() {
    string input = "foxfoxfoxfox";
    string pattern = "fox";
    RabinKarpSearch(input, pattern);
    return 0;
}