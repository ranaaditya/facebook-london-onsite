/**
 * @file trie.cpp
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

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++)
        this->children[i] = NULL;
    }
};

TrieNode *getTrieNode() {
    TrieNode *tmpNode = new TrieNode();
    return tmpNode;
}

void insertIntoTrie(TrieNode *root, string key) {
    TrieNode *crawlerNode = root;
    int keyLength = key.length();

    for(int i = 0; i < keyLength; i++) {
        int index = key[i] - 'a';
        if(!crawlerNode->children[index]) {
            crawlerNode->children[index] = getTrieNode();
        }

        crawlerNode = crawlerNode->children[index];
    }

    crawlerNode->isEndOfWord = true;
}

bool searchInTrie(TrieNode *root, string key) {
    int keyLength = key.length();
    TrieNode *crawlerNode = root;
    for(int i = 0; i < keyLength; i++) {
        int index = key[i] - 'a';
        if(!crawlerNode->children[index])
        return false;

        crawlerNode = crawlerNode->children[index];
    }

    return crawlerNode->isEndOfWord;
}

int main() {
    vector<string> keychain = {"hi", "there", "how", "are", "you"};
    TrieNode *root = new TrieNode();
    for(auto x : keychain)
        insertIntoTrie(root, x);

    for(auto y : keychain)
        cout << " IS " << y << " there in Trie: " << searchInTrie(root, y) << endl;

        cout << "random guess for \" timex \" : " << searchInTrie(root, "timex") << endl;
    return 0;
}