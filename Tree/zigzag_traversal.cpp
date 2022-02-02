/**
 * @file zigzag_traversal.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-02-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        this->value = val;
        left = nullptr;
        right = nullptr;
    }
};

void zigzagTraversal(Node* root) {
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty()) {
        Node* ptr = currentLevel.top();
        currentLevel.pop();

        if(ptr != nullptr) {
            cout << ptr->value << " ";

            if(leftToRight){
                if(ptr->left != nullptr) nextLevel.push(ptr->left);
                if(ptr->right != nullptr) nextLevel.push(ptr->right);
            } else {
                if(ptr->right != nullptr) nextLevel.push(ptr->right);
                if(ptr->left != nullptr) nextLevel.push(ptr->left);
            }
        }
        
        if(currentLevel.empty()) {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    zigzagTraversal(root);

    return 0;
}