#include "igloo/igloo_alt.h"
#include "reversed_strings.h"

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
};