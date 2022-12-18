#include <string>
#include "string_repeat.h"

using namespace std;

string repeat_str(size_t repeat, const string &str) {
    string out = "";
    while (repeat--)
        out += str;
    return out;
}
