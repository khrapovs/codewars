#ifndef CODEWARS_MAIN_H
#define CODEWARS_MAIN_H

#include <string>
#include "003_reversed_strings/reversed_strings.h"

using namespace std;

string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

#endif //CODEWARS_MAIN_H
