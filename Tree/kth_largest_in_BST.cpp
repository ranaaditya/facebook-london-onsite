/**
 * @file kth_largest_in_BST.cpp
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

void printInorderBST(Node* root) {
    if(root == nullptr)
    return;

    printInorderBST(root->left);
    cout << root->value << " ";
    printInorderBST(root->right);
}

void kthLargestInBST(Node* root, int k, int& counter) {
    if(root == nullptr || counter >= k)
    return;

    kthLargestInBST(root->right, k, counter);
    counter++;
    if(counter == k)
    cout << "Kth smallest elemet is: " <<  root->value << endl;
    kthLargestInBST(root->left, k, counter);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    //printInorderBST(root);
    cout << endl;
    int k = 3;
    int c = 0;
    kthLargestInBST(root, k, c);
    return 0;
}