/**
 * @file merge_intervals.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> MergeIntervals(vector<vector<int>> intervals) {
    int length = intervals.size();
    vector<vector<int>> mergedIntervals(length);
    int i = 0, j = 1;
    int index = 0;
    int start = -1, end = -1;
    while(i < length && j < length){
        start = intervals[i][1];
        end = intervals[j][0];

        cout << "start at " << j << " is:\t" << start << endl;
        cout << "end at " << j << " is:\t" << end << endl;
        
        // if(j == length-1) {
        //     mergedIntervals[index].push_back(intervals[i][0]);
        //     mergedIntervals[index].push_back(intervals[j][1]);
        //     index++;
        //     i = j;
        //     i++;
        //     j++;
        //     break;
        // }
         if(end <= start) {
            j++;
            continue;
        }
        else {
            mergedIntervals[index].push_back(intervals[i][0]);
            mergedIntervals[index].push_back(intervals[j-1][1]);
            cout << "Inserted at: " << index << "\t [ " << intervals[i][0] << ", " << intervals[j-1][1] << " ]" <<  endl;
            index++;
            i = j;
            j = i+1;
            cout << "new i is: " << i << "\nnew j is: " << j << endl;
            continue;
        }
        continue;
    }

    if(i < length) {
        if(j > length) {
            if(i == length-1) {
                mergedIntervals[index].push_back(intervals[i][0]);
                mergedIntervals[index].push_back(intervals[i][1]);
                index++;
            }else {
                mergedIntervals[index].push_back(intervals[i][0]);
                mergedIntervals[index].push_back(intervals[length-1][1]);
                cout << "Inserted at: " << index << "\t [ " << intervals[i][0] << ", " << intervals[length-1][1] << " ]" <<  endl;
                index++;
            }
        }
    }
    return mergedIntervals;
}

int main() {
    vector<vector<int>> v = {{1,3}, {2,6}, {8,10}, {15, 18}};
    cout << v.size() << endl;
    auto output = MergeIntervals(v);

    for(auto x : output) {
        for(auto y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }

    return 0;
}