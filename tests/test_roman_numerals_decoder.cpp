#include <string>
#include <regex>
#include <vector>
#include <ctime>

#include "igloo/igloo_alt.h"
#include "012_roman_numerals_decoder/roman_numerals_decoder.h"

using namespace std;
using namespace igloo;


Describe(your_roman_numerals_decoder_solution) {
    It(should_work_for_the_code_example_in_the_description) {
        Assert::That(solution("XXI"), Equals(21));
    }

    It(should_work_for_a_few_other_examples) {
        Assert::That(solution("I"), Equals(1));
        Assert::That(solution("IV"), Equals(4));
        Assert::That(solution("MMVIII"), Equals(2008));
        Assert::That(solution("MDCLXVI"), Equals(1666));
    }

    It(should_work_for_some_fixed_tests) {
        Assert::That(solution("MM"), Equals(2000));
        Assert::That(solution("MDC"), Equals(1600));
        Assert::That(solution("L"), Equals(50));
        Assert::That(solution("XL"), Equals(40));
        Assert::That(solution("XC"), Equals(90));
        Assert::That(solution("XCV"), Equals(95));
        Assert::That(solution("III"), Equals(3));
    }

    It(should_work_for_some_advanced_roman_numerals) {
        Assert::That(solution("MCMLIV"), Equals(1954));
        Assert::That(solution("MDCXLVII"), Equals(1647));
        Assert::That(solution("CDXCIV"), Equals(494));
        Assert::That(solution("MMXVII"), Equals(2017));
        Assert::That(solution("MCCCXXXVII"), Equals(1337));
        Assert::That(solution("XLII"), Equals(42));
    }

    It(should_work_for_some_randomly_generated_valid_roman_numerals) {
        srand(time(NULL));
        auto reference = [](string s) -> int {
            int result = 0;
            regex m("^M"), cm("^CM"), d("^D"), cd("^CD"), c("^C"), xc("^XC"), l("^L"), xl("^XL"), x("^X"), ix("^IX"), v(
                    "^V"), iv("^IV");
            while (regex_search(s, m)) {
                s = regex_replace(s, m, "");
                result += 1000;
            }
            while (regex_search(s, cm)) {
                s = regex_replace(s, cm, "");
                result += 900;
            }
            while (regex_search(s, d)) {
                s = regex_replace(s, d, "");
                result += 500;
            }
            while (regex_search(s, cd)) {
                s = regex_replace(s, cd, "");
                result += 400;
            }
            while (regex_search(s, c)) {
                s = regex_replace(s, c, "");
                result += 100;
            }
            while (regex_search(s, xc)) {
                s = regex_replace(s, xc, "");
                result += 90;
            }
            while (regex_search(s, l)) {
                s = regex_replace(s, l, "");
                result += 50;
            }
            while (regex_search(s, xl)) {
                s = regex_replace(s, xl, "");
                result += 40;
            }
            while (regex_search(s, x)) {
                s = regex_replace(s, x, "");
                result += 10;
            }
            while (regex_search(s, ix)) {
                s = regex_replace(s, ix, "");
                result += 9;
            }
            while (regex_search(s, v)) {
                s = regex_replace(s, v, "");
                result += 5;
            }
            while (regex_search(s, iv)) {
                s = regex_replace(s, iv, "");
                result += 4;
            }
            return result + s.length();
        };
        int i = 0;
        while (i < 100) {
            string s = string(rand() % 4, 'M') +
                       (vector<string>{"CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C", ""})[rand() % 10] +
                       (vector<string>{"XC", "LXXX", "LXX", "LX", "L", "XL", "XXX", "XX", "X", ""})[rand() % 10] +
                       (vector<string>{"IX", "VIII", "VII", "VI", "V", "IV", "III", "II", "I", ""})[rand() % 10];
            if (s.length() > 0) {
                int expected = reference(s), actual = solution(s);
                Assert::That(actual, Equals(expected));
                i++;
            }
        }
    }
};
