#include <vector>
#include "map"
#include "roman_numerals_decoder.h"

using namespace std;

int solution(string roman) {
    map<char, int> roman_to_int = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int total = 0;
    for (int i = 0; i < roman.length(); i++) {
        if (roman_to_int[roman[i]] >= roman_to_int[roman[i + 1]]) {
            total += roman_to_int[roman[i]];
        } else {
            total -= roman_to_int[roman[i]];
        }
    }
    return total;
}
