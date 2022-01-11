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
 * #3:
 * 
 * Input: s = "."
 * 
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 20
 * 
 * s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot
 * 
 */
#include<bits/stdc++.h>
using namespace std;

bool isValidNum(char ch) {
    return ((ch - '0') >= 0 && (ch - '0') <= 9);
}

bool isValidSign(char sign) {
    return (sign == '+' || sign == '-');
}

bool isExponenetial(char exp) {
    return ((exp == 'e') || (exp == 'E'));
}

bool validNumberImproved(string num) {
    int index = 0;
    bool isSign = false;
    bool isE = false;
    bool isDecimal = false;
    int length = num.length();
    
    if(length < 2) {
        return isValidNum(num[0]);
    }

    for(int i = 0; i < length ; i++) {
        if(isValidSign(num[i])){
            if(i == 0) continue;
            else if((i > 0 && i <= length-2) && isExponenetial(num[i-1]))continue;
            else return false;
        } else if(isValidNum(num[i])) {
            continue;
        } else if(num[i] == '.') {
            if((i > 0 && i <= length-2) && (isValidNum(num[i-1]) && isValidNum(num[i+1]))) {
                continue;
            } else return false;
        } else if(isExponenetial(num[i])) {
            if((i > 0 && i <= length-2)) {
                if(isValidSign(num[i+1]) && isValidNum(num[i+2])) continue;
                else if(isValidNum(num[i+1]) && isValidNum(num[i-1])) continue;
                else return false;
            } else return false;
        }
    }

    return true;
}

int main() {
    string str = "1e-4";
    cout << validNumberImproved(str) << endl;
    return 0;
}