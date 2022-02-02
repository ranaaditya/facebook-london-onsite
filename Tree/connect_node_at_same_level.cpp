/**
 * @file connect_node_at_same_level.cpp
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
    Node* nextRight;

    Node(int val) {
        this->value = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

void connectNodeAtSameLevel(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        Node* ptr = q.front();
        q.pop();

        if(ptr != nullptr) {
            ptr->nextRight = q.front();

            if(root->left != nullptr) q.push(root->left);
            if(root->right!= nullptr) q.push(root->right);
            
        }else if(!q.empty()){
            q.push(nullptr);
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

    connectNodeAtSameLevel(root);
    return 0;
}