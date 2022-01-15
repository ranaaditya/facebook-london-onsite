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
    deque<int> dq;
    bool isIncreasingSequence;

    public:
    MonotonicQueue(bool isIncreasing) {
        this->isIncreasingSequence = isIncreasing;
    }

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

    int back() {
        return dq.back();
    }

    int front() {
        return dq.front();
    }

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

    mq.print();
    return 0;
}