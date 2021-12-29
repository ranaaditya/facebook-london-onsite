/**
 * @file string_tokenization.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2021-12-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<bits/stdc++.h>
using namespace std;

char* STRTOK(char* str, char delim) {
    static char* input = NULL;

    if(str!=NULL) {
        // initialization of static character array
        input = str;
    }

    if(input == NULL) {
        return NULL;
    }

    // Tokenization
    char* output = new char[strlen(input)+1];
    int index = 0;

    for(; input[index] != '\0'; index++) {

        if(input[index] != delim) {
            output[index] = input[index];
        } else {
            output[index] = '\0';
            input = input + index + 1;
            return output;
        }
    }
    
    output[index] = '\0';
    input = NULL;
    return output;

}


int main() {

    char s[] = "Today is a sunny day";
    char* ptr = STRTOK(s, ' ');

    while(ptr !=NULL) {
        cout << ptr << endl;
        ptr = STRTOK(NULL, ' ');
    }
    
    return 0;
}