/**
 * @file randomizer.cpp
 * @author Aditya Rana
 * @brief 
 * @version 0.1
 * @date 2022-01-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * std::random_device device
 * 
 * This is a special class which produces uniformly-distributed unsigned integers with 32 bits of length. 
 * It can produce random numbers either by accessing the operational system's entropy pool via system calls 
 * or by using hardware random number generators such as Intel's RdRand when available 
 * (but not all implementations of std::random_device allow this). Developers must be warned, however, that even 
 * though 32-bit unsigned integers are generated, the entropy of this random number generator may be lower than 32 bits.
 * 
 * Unfortunately, it is not advisable to use std::random_device repeatedly as this may quickly deplete the entropy 
 * pool and therefore reduce the level of randomness available to the other processes running in the system. Additionally, 
 * its reliance on system calls makes it a very slow random number generator.
 * 
 * use std::random_device to generate a single random number which is then used as a seed for a pseudorandom number 
 * generator (PRNG) and then use the PRNG itself to generate as many pseudorandom numbers as we wish.
 * 
 * 
 * std::uniform_int_distribution
 * 
 * Produces random integer values i, uniformly distributed on the closed interval [a,b], 
 * that is, distributed according to the discrete probability function.
 * 
 * Using its overloaded operator(), an object of type std::uniform_int_distribution can take a random number generator and use 
 * it to generate a number within its defined target interval. Indeed, the following expression in our code returns a number in  [a,b]
 * 
 */
#include<bits/stdc++.h>
using namespace std;

int randomizer(int low, int high) {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(low, high);

    return distribution(generator);
}

float randomizer (float low, float high) {
    random_device rd;
    default_random_engine dre(rd());
    uniform_real_distribution<float> uid(low, high);

    return (float) uid(dre);
}

double randomizer(double low, double high){
    random_device rd;
    default_random_engine dre(rd());
    uniform_real_distribution<double> uid(low, high);

    return (float) uid(dre);
}

char randomizer(char low, char high) {
    int shiftLow = low - 'a';
    int shiftHigh = high - 'a';

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(shiftLow, shiftHigh);

    return distribution(generator) + 'a';

}

int reproducibleRandomizer(int low, int high) {
/* seed the PRNG (MT19937) using a fixed value (in our case, 0) */
    mt19937 generator(0);
    uniform_int_distribution<int> distribution(low, high);

    return distribution(generator);
}

int main() {
    double start = 0.00;
    double end = 10.00;

    char low = 'a';
    char high = 'z';

    for(int i = 0; i < 5; i++){
        cout << randomizer(low, high) << endl;
    }

    return 0;
}