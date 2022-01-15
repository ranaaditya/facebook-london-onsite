/**
 * @file MonotonicQueue.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class MonotonicQueue {
    private:
    /**
     * @brief Deque has been used here just to have flexibility to add elements both from rear and front
     * 
     * Deque is more flexible than Queue
     * 
     */
    deque<int> dq;
    /**
     * @brief this flag is use to differentiate between the increasing or decreasing nature of the monotonic queue
     * 
     */
    bool isIncreasingSequence;

    public:
    MonotonicQueue(bool isIncreasing) {
        this->isIncreasingSequence = isIncreasing;
    }

    /**
     * @brief for inserting an element from the last of the queue
     * 
     * @param value 
     */
    void push_back(int value) {
        if(isIncreasingSequence) {
            while(!dq.empty() && dq.back() >= value)
                dq.pop_back();

            dq.push_back(value);
        } else {
            while(!dq.empty() && dq.back() <= value)
                dq.pop_back();

            dq.push_back(value);
        }
    }

    /**
     * @brief for adding element from the starting of the queue
     * 
     * @param value 
     */
    void push_front(int value) {
        if(isIncreasingSequence) {
            while(!dq.empty() && dq.front() <= value)
                dq.pop_front();

            dq.push_front(value);
        } else {
            while(!dq.empty() && dq.front() >= value)
                dq.pop_front();
            
            dq.push_front(value);
        }
    }    

    /**
     * @brief for getting l-value of the last element in the queue
     * 
     * @return int 
     */
    int back() {
        return dq.back();
    }

    /**
     * @brief for getting the first element in the queue
     * 
     * @return int 
     */
    int front() {
        return dq.front();
    }

    /**
     * @brief prints the entire queue
     * 
     */
    void print() {
        for(auto x : dq)
        cout << x << "\t";
    }
};

int main() {
    MonotonicQueue mq(true);

    for(int i = 0; i < 6; i++) {
        mq.push_back(i);
    }

    mq.print(); // 0 1 2 3 4 5
    return 0;
}