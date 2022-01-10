/**
 * @file BinaryIndexTree.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Fenwick Tree or Binary Index Tree
 * 
 * Height: maximum of log(n)
 * 
 * GetSum(0, n): log(n)
 * 
 * Updatevalue(index, newvalue): log(n)
 * 
 * Size of internal array used to create BIT: O(n+1)
 * 
 * 
 * BIT are used to get sum of first i elements in log(n)
 * 
 * These are better than Segment trees as they take less space / same as that of the input array
 * 
 * Both BIT and Segement Trees have same time complexity for updation and getting sum operations.
 * 
 */
class BinaryIndexTree {
    private:
    int length;
    vector<int> bit;

    public:
    BinaryIndexTree(int treeLength){
        this->length = treeLength + 1;
        bit.assign(treeLength, 0);
    }

    BinaryIndexTree(vector<int> bitArray){
        this->length = bitArray.size() + 1;
        bit.assign(this->length, 0);
        createBinaryIndexTreeFromArray(bitArray, this->length);
    }

    void createBinaryIndexTreeFromArray(vector<int> arr, int length) {
        for(int i = 1; i < length; i++) {
            updateBinaryIndexTree(i, arr[i-1]);
        }
    }

    /**
     * @brief Get the Next object
     * 
     * Steps:
     * 
     * 1. 2's complement to get the minus index
     * 2. AND with this index
     * 3. Subtract that from index
     * 
     * @param index 
     * @return int 
     */
    int getNext(int index) {
        return index + (index & -index);
    }

    /**
     * @brief Get the Parent object
     * 
     * Steps:
     * 
     * 1. 2's complement to get the minus index
     * 2. AND this with index
     * 3. Subtract that from index
     * 
     * @param index 
     * @return int 
     */
    int getParent(int index) {
        return index - (index & -index);
    }

    int getSum(int index) {
        index = index + 1;
        int sum = 0;
        while(index > 0) {
            sum += bit[index];
            index = getParent(index);
        }
        return sum;
    }

    vector<int> getBinaryIndexTree() {
        return this->bit;
    }

    void updateBinaryIndexTree(int index, int updatedvalue) {
        while(index < this->length) {
            bit[index] += updatedvalue;
            index = getNext(index);
        }
    }

};

int main() {
    //vector<int> arr = {3,2,-1,6,5,4,-3,3,7,2,3};
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    BinaryIndexTree bit = BinaryIndexTree(arr);
    auto x = bit.getBinaryIndexTree();

    for(auto y : x)
    cout << y << "\t";
    cout << endl;

    cout << "sum of first 5 elements: " << bit.getSum(5) << endl;
    return 0;
}