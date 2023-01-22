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

    vector<int> numbers = {};
    for (char letter: roman) {
        numbers.push_back(roman_to_int[letter]);
    }

    int out = 0;
    int temp;

    for (int i = 0; i < numbers.size(); ++i) {
        temp = 0;
        if (i + 1 == numbers.size()) {
            temp += numbers[i];
        } else {
            for (int j = i; j < numbers.size(); ++j) {
                if (j + 1 < numbers.size()) {
                    if (numbers[j] >= numbers[j + 1]) {
                        temp += numbers[j];
                        break;
                    } else { temp -= numbers[j]; }
                }
            }
        }
        out += temp;
    }
    return out;
}
