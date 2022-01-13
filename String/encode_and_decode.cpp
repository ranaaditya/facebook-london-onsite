/**
 * @file encode_and_decode.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Problem:
 * 
 * Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 * 
 * Machine 1 (sender) has the function:
 * 
 * string encode(vector<string> strs) {
 * 
 *  // ... your code
 * 
 *  return encoded_string;
 * 
 *  }
 * 
 * Machine 2 (receiver) has the function:
 * 
 * vector<string> decode(string s) {
 * 
 * //... your code
 * 
 * return strs;
 * 
 * }
 * 
 * So Machine 1 does:
 * 
 * string encoded_string = encode(strs);
 * 
 * and Machine 2 does:
 * 
 * 
 * vector<string> strs2 = decode(encoded_string);
 * 
 * strs2 in Machine 2 should be the same as strs in Machine 1.
 * 
 * Implement the encode and decode methods.
 * 
 * 
 * You are not allowed to solve the problem using any serialize methods (such as eval).
 * 
 * TestCases:
 * 
 * #1:
 * 
 * Input: dummy_input = ["Hello","World"]
 * 
 * Output: ["Hello","World"]
 * 
 * 
 * Explanation:
 * 
 * Machine 1:
 * 
 * Codec encoder = new Codec();
 * 
 * String msg = encoder.encode(strs);
 * 
 * Machine 1 ---msg---> Machine 2
 * 
 * 
 * Machine 2:
 * 
 * Codec decoder = new Codec();
 * 
 * String[] strs = decoder.decode(msg);
 * 
 * #2:
 * 
 * Input: dummy_input = [""]
 * 
 * Output: [""]
 * 
 * 
 * Constraints:
 * 
 * 1 <= strs.length <= 200
 * 
 * 0 <= strs[i].length <= 200
 * 
 * strs[i] contains any possible characters out of 256 valid ASCII characters.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

string encodeInput(vector<string> input) {
    string encodedString;

    for(auto part : input) {
        int partLength = part.length();
        encodedString += to_string(partLength) + '#' + part;
    }
    return encodedString;
}

vector<string> decodeInput(string input) {
    vector<string> decodedStrings;
    int length = input.length();
    int index = 0;
    while(index < length) {
        int len = input[index] - '0';
        decodedStrings.push_back(input.substr(index+2, len));
        index += (len + 2);
    }
    return decodedStrings;
}

int main() {
    vector<string> words = {"Hello","World"};
    string encstr = encodeInput(words);
    cout << encstr << endl;

    vector<string> dcdstr = decodeInput(encstr);

    for(auto x : dcdstr)
    cout << x << "\n";

    cout << endl;
    return 0;
}