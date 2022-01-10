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


/**
 * Problem:
 * 
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
 * and return an array of the non-overlapping intervals that cover all the intervals in the input.
 * 
 * #1:
 * 
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 
 * Output: [[1,6],[8,10],[15,18]]
 * 
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * 
 * #2:
 * 
 * Input: intervals = [[1,4],[4,5]]
 * 
 * Output: [[1,5]]
 * 
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> MergeIntervals(vector<vector<int>> intervals) {
//     int length = intervals.size();
//     vector<vector<int>> mergedIntervals(length);
//     int i = 0, j = 1;
//     int index = 0;
//     int start = -1, end = -1;
//     while(i < length && j < length){
//         start = intervals[i][1];
//         end = intervals[j][0];

//         cout << "start at " << j << " is:\t" << start << endl;
//         cout << "end at " << j << " is:\t" << end << endl;
        
//         // if(j == length-1) {
//         //     mergedIntervals[index].push_back(intervals[i][0]);
//         //     mergedIntervals[index].push_back(intervals[j][1]);
//         //     index++;
//         //     i = j;
//         //     i++;
//         //     j++;
//         //     break;
//         // }
//          if(end <= start) {
//             j++;
//             continue;
//         }
//         else {
//             mergedIntervals[index].push_back(intervals[i][0]);
//             mergedIntervals[index].push_back(intervals[j-1][1]);
//             cout << "Inserted at: " << index << "\t [ " << intervals[i][0] << ", " << intervals[j-1][1] << " ]" <<  endl;
//             index++;
//             i = j;
//             j = i+1;
//             cout << "new i is: " << i << "\nnew j is: " << j << endl;
//             continue;
//         }
//         continue;
//     }

//     if(i < length) {
//         if(j > length) {
//             if(i == length-1) {
//                 mergedIntervals[index].push_back(intervals[i][0]);
//                 mergedIntervals[index].push_back(intervals[i][1]);
//                 index++;
//             }else {
//                 mergedIntervals[index].push_back(intervals[i][0]);
//                 mergedIntervals[index].push_back(intervals[length-1][1]);
//                 cout << "Inserted at: " << index << "\t [ " << intervals[i][0] << ", " << intervals[length-1][1] << " ]" <<  endl;
//                 index++;
//             }
//         }
//     }
//     return mergedIntervals;
// }


    bool compare(vector<int> a, vector<int> b) {
        return a[0] > b[0];
    }

    vector<vector<int>> MergeIntervals(vector<vector<int>> intervals) {
        int index = 0;
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());

        for(auto interval : intervals) {
            if(merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }

int main() {
    vector<vector<int>> v = {{1,3}, {2,6}, {8,10}, {15, 18}};
    //cout << v.size() << endl;
    auto output = MergeIntervals(v);

    for(auto x : output) {
        for(auto y : x) {
            cout << y << "\t";
        }
        cout << endl;
    }

    return 0;
}