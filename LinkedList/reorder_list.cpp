/**
 * @file reorder_list.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;


struct LinkedListNode {
    int value;
    LinkedListNode* next;

    LinkedListNode(int val) {
        this->value = val;
        this->next = nullptr;
    }

    LinkedListNode(int val, LinkedListNode* nxt) {
        this->value = val;
        this->next = nxt;
    }
};

void insert(LinkedListNode* head, int val) {
    if(head == nullptr)
    return;

    LinkedListNode* ptr = head;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }

    LinkedListNode* tmp = new LinkedListNode(val);
    ptr->next = tmp;
    ptr = ptr->next;
}

void printLinkedList(LinkedListNode* head) {
    LinkedListNode* ptr = head;

    while(ptr != nullptr) {
        cout << ptr->value << "\n";
        ptr = ptr->next;
    }
}

LinkedListNode* reverseList(LinkedListNode* head) {
    LinkedListNode *prev = nullptr, *current = head,* next = nullptr;

    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


LinkedListNode* reorderLinkedList(LinkedListNode* head) {
    LinkedListNode *current = head;

    LinkedListNode* ptr = head;
    int length = 0;

    while(ptr != nullptr) {
        length++;
        ptr = ptr->next;
    }

    int ltraverse = (length%2 == 0) ? length/2 : (length/2)+1 ;

    while( ltraverse > 0) {
        current = current->next;
    }


    LinkedListNode* lHead =  reverseList(current);
    current = head;

    LinkedListNode *oldPtr = head, *newPtr = lHead;
    LinkedListNode *nextOld = head, *nextNew = lHead;

    while(oldPtr != nullptr && newPtr != nullptr) {
        nextOld = current->next;
        nextNew = newPtr->next;
        oldPtr->next = newPtr;
        oldPtr = nextOld;
        newPtr = nextNew;
    }

    return head;
}
int main() {
    LinkedListNode *ll = new LinkedListNode(0);
    for(int i = 1; i < 6; i++)
    insert(ll, i);

    // LinkedListNode *rl =  reverseList(ll);
    // printLinkedList(rl);

    reorderLinkedList(ll);
    printLinkedList(ll);
    return 0;
}