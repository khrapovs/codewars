#include "igloo/igloo_alt.h"
#include "005_convert_string_to_number/convert_string_to_number.h"

#include <random>
#include <string>

using namespace igloo;

Describe(stringToNumber) {
    It(shouldWorkForTheExamples) {
        AssertThat(string_to_number("1234"), Is().EqualTo(1234));
        AssertThat(string_to_number("605"), Is().EqualTo(605));
        AssertThat(string_to_number("1405"), Is().EqualTo(1405));
        AssertThat(string_to_number("-7"), Is().EqualTo(-7));
    }

    It(shouldWorkWithRandomNumbers) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

        for (int i(0); i < 100; ++i) {
            int random_integer = uni(rng);
            AssertThat(string_to_number(std::to_string(random_integer)), Is().EqualTo(random_integer));
        }
    }
};
