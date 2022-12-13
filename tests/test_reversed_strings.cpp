#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "igloo/igloo_alt.h"
#include "003_reversed_strings/reversed_strings.h"

using namespace std;
using namespace igloo;

Describe(Reverse_String) {
    It(Check_Short_Words) {
        Assert::That(reverseString("hello"), Equals("olleh"));
        Assert::That(reverseString("rat"), Equals("tar"));
        Assert::That(reverseString("alpha"), Equals("ahpla"));
    }

    It(Check_Longer_Words) {
        Assert::That(reverseString("codewars"), Equals("srawedoc"));
        Assert::That(reverseString("football"), Equals("llabtoof"));
        Assert::That(reverseString("translation"), Equals("noitalsnart"));
    }

    string modelSolution(string str) {
        reverse(str.begin(), str.end());
        return str;
    }

    It(generate_random_string) {
        static const string charList = "abcdefghijklmnopqrstuvwxyz";
        srand(time(0));

        string alphanumeric;
        for (int i = 0; i < 15; i++) {
            alphanumeric += charList[rand() % 13 + 2];
        }
        string result = modelSolution(alphanumeric);
        Assert::That(reverseString(alphanumeric), Equals(result));
    }
};