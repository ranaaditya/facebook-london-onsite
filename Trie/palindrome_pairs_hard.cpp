/**
 * @file palindrome_pairs_hard.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief brute force with nested loops
 * 
 * Time complexity: O((N^2).K), where `K` is the length of the longest string in words
 * Space Complexity: O(N^2) (worst case), for storing the resultant palindromic vector of strings
 * 
 * @param words 
 * @return vector<string> 
 */
vector<string> palindromePairs(vector<string> words) {
    vector<string> palindromicwords;
    int length = words.size();
    string tempWord, reversedWord;
    
    for(int i = 0; i < length-1; i++) {
        for(int j = i+1; j < length; j++) {
            tempWord = words[i] + words[j];
            reversedWord = tempWord;
            reverse(reversedWord.begin(), reversedWord.end());
            if(reversedWord == tempWord) {
                palindromicwords.push_back(tempWord);
            }

            // reverse case when a + b si also palindromic for b + a
            tempWord = words[j] + words[i];
            reversedWord = tempWord;
            reverse(reversedWord.begin(), reversedWord.end());
            if(reversedWord == tempWord) {
                palindromicwords.push_back(tempWord);
            }
        }
    }
    return palindromicwords;
}

// optimal solution using valid prefixes and suffixes
// Time Complexity: O((k^2)N), k is the length of the longest string in input array

/**
 * @brief both start and end are inclusive -> [start, end]
 * 
 * @param word 
 * @param start 
 * @param end 
 * @return true 
 * @return false 
 */
bool isValidPalindromeInBetween(string word, int start, int end) {
    while(start < end) {
        if(word[start] != word[end]) return false;
        else {
            start++;
            end--;
        }
    }
    return true;
}

vector<string> generateAllValidPrefixes(string word) {
    vector<string> validPrefixes;
    int length = word.length();

    for(int i = 0; i < length; i++) {
        if(isValidPalindromeInBetween(word, 0, i)) validPrefixes.push_back(word.substr(0,i+1));
    }
    return validPrefixes;
}

vector<string> generateAllValidSuffixes(string word) {
    vector<string> validSuffixes;
    int length = word.length();

    for(int i = 0; i < length; i++) {
        if(isValidPalindromeInBetween(word, length-1-i, length-1)) validSuffixes.push_back(word.substr(length-1-i, length));
    }
    return validSuffixes;
}

vector<string> palindromePairsImproved(vector<string> words) {
    vector<string> palindromicWords;
    map<string, int> wordMap;
    int length = words.size();

    for(auto x : words) {
        wordMap[x]++;
    }
    
    vector<vector<string>> allPrefixes(length), allSuffixes(length);

    for(int i = 0; i < length; i++) {
        allPrefixes[i] = generateAllValidPrefixes(words[i]);
        allSuffixes[i] = generateAllValidSuffixes(words[i]);
    }
    // find the remaining substring from prefixes and suffixes and reverse thema dn search in the map if they are in map then we have founf a palindromic pair else repeat the steps again to go over the words array
    return palindromicWords;
}

int main() {
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    auto output = palindromePairs(words);

    for(auto x : output)
    cout << x << "\t";

    cout << endl;

    // string str = "banana";
    // auto prfx = generateAllValidSuffixes(str);
    // for(auto x : prfx)
    // cout << x << "\t";
    return 0;
}