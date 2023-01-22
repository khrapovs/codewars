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
};
