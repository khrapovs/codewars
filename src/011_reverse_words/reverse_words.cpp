#include "string"
#include "reverse_words.h"

using namespace std;

string reverse_words(string str) {
    string delim = " ";
    string reversed_str;
    string word;
    size_t start, end = -1;
    do {
        start = end + delim.size();
        end = str.find(delim, start);
        word = str.substr(start, end - start);
        reverse(word.begin(), word.end());
        reversed_str += word + ((end != -1) ? delim : "");
    } while (end != -1);
    return reversed_str;
}
