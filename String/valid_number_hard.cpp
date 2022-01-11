/**
 * @file valid_number_hard.cpp
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
 * A valid number can be split up into these components (in order):
 * 
 * - A decimal number or an integer.
 * 
 * - (Optional) An 'e' or 'E', followed by an integer.
 * 
 * - A decimal number can be split up into these components (in order):
 * 
 * (Optional) A sign character (either '+' or '-').
 * 
 * One of the following formats:
 * 
 * One or more digits, followed by a dot '.'.
 * 
 * One or more digits, followed by a dot '.', followed by one or more digits.
 * 
 * A dot '.', followed by one or more digits.
 * 
 * 
 * An integer can be split up into these components (in order):
 * 
 * (Optional) A sign character (either '+' or '-').
 * 
 * One or more digits.
 * 
 * 
 * 
 * For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].
 * 
 * Given a string s, return true if s is a valid number.
 * 
 * TestCases:
 * 
 * #1:
 * 
 * Input: s = "0"
 * 
 * Output: true
 * 
 * #2:
 * 
 * Input: s = "e"
 * 
 * Output: false
 * 
 * #3:
 * 
 * Input: s = "."
 * 
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * -> 1 <= s.length <= 20
 * 
 * -> s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot
 * 
 */
#include<bits/stdc++.h>
using namespace std;

bool isValidNum(char ch) {
    return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == 'e' || ch == 'E' || ch == '+' || ch == '-');
}

bool isValidNumber(string num) {
    int length = num.length();
    if(length == 1 && (num[0] == 'e' || num[0] == '.')) return false;
    int index = 0;
    bool signing = (num[0] == '+' || num[0] == '-');
    if(signing) index = 1;

    for(; index < length; index++) {
        if(isValidNum(num[index])) continue;
        else if(num[index] == '.') continue;
        else return false;
    }

    return true;
}
int main() {
    string str = "e";
    cout << isValidNumber(str) << endl;
    return 0;
}