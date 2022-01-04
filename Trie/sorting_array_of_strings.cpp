/**
 * @file sorting_array_of_strings.cpp
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

#define CHARSET_SIZE 26

struct TrieNode {
    struct TrieNode *children[CHARSET_SIZE];
    int index;
    
    TrieNode() {
        for(int i = 0; i < CHARSET_SIZE; i++)
        this->children[i] = NULL;

        this->index = -1;
    }
};

void insertIntoTrie(TrieNode *root, string key, int input_index) {
    int keyLength = key.length();

    TrieNode *crawlerNode = root;

    for(int i = 0; i < keyLength; i++) {
        int ind = key[i] - 'a';

        if(!crawlerNode->children[ind])
        crawlerNode->children[ind] = new TrieNode();

        crawlerNode = crawlerNode->children[ind];
    }

    crawlerNode->index = input_index;
}

void preOrderInTrie(TrieNode *root, vector<string> keychain) {
    if(root == NULL)
    return;

    for(int i = 0; i < CHARSET_SIZE; i++) {
        if(root->children[i] != NULL) {
            if(root->children[i]->index != -1) {
                cout << keychain[root->children[i]->index] << endl;
            }
            preOrderInTrie(root->children[i], keychain);
        }
    }
}

TrieNode *getTrieNode() {
    TrieNode *tmpNode = new TrieNode();
    return tmpNode;
}

int main() {

    vector<string> keychain = {"aditya", "rana", "is", "a", "billionare"};

    TrieNode *root = new TrieNode();

    for(int i = 0; i < keychain.size(); i++) {
        insertIntoTrie(root, keychain[i], i);
    }

    preOrderInTrie(root, keychain);
    return 0;
}