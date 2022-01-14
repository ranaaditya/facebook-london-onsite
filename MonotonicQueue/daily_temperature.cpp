/**
 * @file daily_temperature.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] 
 * is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for 
 * which this is possible, keep answer[i] == 0 instead.
 * 
 * TestCases:
 * 
 * #1:
 * 
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * 
 * Output: [1,1,4,2,1,1,0,0]
 * 
 * #2:
 * 
 * Input: temperatures = [30,40,50,60]
 * 
 * Output: [1,1,1,0]
 * 
 * #3:
 * 
 * Input: temperatures = [30,60,90]
 * 
 * Output: [1,1,0]
 * 
 * 
 * Constraints:
 * 
 * 1 <= temperatures.length <= 105
 * 
 * 30 <= temperatures[i] <= 100
 * 
 */
#include<bits/stdc++.h>
using namespace std;
/**
 * @brief Decreasing Monotonous Queue will be used.
 * 
 * Time Complexity: O(N)
 * 
 * Space Complexity: O(N) (worst case)
 * 
 * @param temperatures 
 * @return vector<int> 
 */
vector<int> dailyTemperature(vector<int> temperatures) {
    int numberOfDays = temperatures.size();
    vector<int> nextHighTemperatures(numberOfDays, 0);
    deque<int> indices;
    indices.push_back(numberOfDays-1);
    
    for(int i = numberOfDays-2; i >= 0; i--) {
        
        while( !indices.empty() && temperatures[indices.back()] <= temperatures[i]) {
            indices.pop_back();
        }

        if(!indices.empty())
        nextHighTemperatures[i] = indices.back() - i;

        indices.push_back(i);
    }

    return nextHighTemperatures;
}

// space optimized solution O(1)
vector<int> dailyHighTemperatureOptimized(vector<int> temperatures) {
    int length = temperatures.size();
    vector<int> nextHighTemperature(length, 0);
    int maxTemperature = 0;

    for(int i = length-1; i >= 0; i--) {
        int currentTemperature = temperatures[i];

        if(currentTemperature >= maxTemperature){
            maxTemperature = currentTemperature;
            continue;
        }

        int days = 1;
        while(temperatures[i + days] <= currentTemperature) {
            days += nextHighTemperature[i + days];
        }

        nextHighTemperature[i] = days;
    }

    return nextHighTemperature;
}
int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto output = dailyHighTemperatureOptimized(temperatures);

    for(auto x : output)
    cout << x << "\t";

    cout << endl;
    return 0;
}