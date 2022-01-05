/**
 * @file copy_list_with_random-pointer.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
 * 
 * 
 * For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
 * 
 * - val: an integer representing Node.val
 * 
 * - random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
 * 
 * 
 * Your code will only be given the head of the original linked list.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct LinkedListNode {
    int value;
    LinkedListNode* next;
    LinkedListNode* random;

    LinkedListNode(int val) {
        this->value = val;
        next = nullptr;
        random = nullptr;
        cout << "DEBUG : " << " VALUE : " << this->value << endl;
    }

    LinkedListNode(int val, LinkedListNode* nxt) {
        this->value = val;
        next = nxt;
        random = nullptr;
    }

    LinkedListNode(int val, LinkedListNode* nxt, LinkedListNode* rnd) {
        this->value = val;
        this->next = nxt;
        this->random = rnd;
    }
};

void printLinkedList(LinkedListNode* head) {
    LinkedListNode* ptr = head;

    while(ptr != nullptr) {
        cout << ptr->value << "\n";
        ptr = ptr->next;
    }
}

/**
 * @brief 
 * This solution takes O(N) time and Space as well !
 * 
 * Doing it in O(1) is quite hard !
 * 
 * @param head 
 */
void CopyLinkedListWithrandomPointer(LinkedListNode *head){
    map<LinkedListNode*, LinkedListNode*> hmap;

    LinkedListNode* ptr = head;

    while(ptr != nullptr) {
        LinkedListNode* nptr = new LinkedListNode(ptr->value);
        hmap.insert({ptr, nptr});
        ptr = ptr->next;
    }

    for(auto x : hmap) {
        x.second->next = hmap[x.first->next];
        x.second->random = hmap[x.first->random];
    }

    cout << endl << "just before copy" << endl;
    printLinkedList(hmap[head]);
}

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

LinkedListNode* DeepCopy(LinkedListNode* oldHead) {
    if(oldHead == nullptr) return nullptr;
    LinkedListNode* newHead = new LinkedListNode(oldHead->value);
    LinkedListNode* ptr = oldHead->next;
    LinkedListNode* nptr = newHead;

    while(ptr != nullptr) {
       LinkedListNode* tmp = new LinkedListNode(ptr->value);
       nptr->next = tmp;
       nptr = nptr->next;
       ptr = ptr->next;
    }
    
    return newHead;
}


void DeepCopyEfficiently(LinkedListNode* head) {
    LinkedListNode* current = head, *tmp;

    while(current != nullptr) {
        tmp = current->next;
        current->next = new LinkedListNode(current->value);
        current->next->next = tmp;
        current = tmp;
    }

    current = head;

    while(current != nullptr) {
        current->next->random = current->random->next;
        current = current->next->next;
    }

    current = head;
    LinkedListNode* newHead = current->next, *nptr = current->next;

    while(current != nullptr) {
        nptr = current->next;
        current->next = current->next->next;
        current = current->next->next;
        nptr->next = current->next;
    }

    printLinkedList(newHead);
}
int main() {
    LinkedListNode* head = new LinkedListNode(0);
    for(int i = 1; i < 6; i++)
    insert(head, i);

    //printLinkedList(head);
    // LinkedListNode* ll =  DeepCopy(head);
    // printLinkedList(ll);
    //CopyLinkedListWithrandomPointer(head);
    DeepCopyEfficiently(head);
    return 0;
}