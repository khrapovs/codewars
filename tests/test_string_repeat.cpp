#include <algorithm>
#include <iterator>
#include <random>
#include "igloo/igloo_alt.h"
#include "008_string_repeat/string_repeat.h"

using namespace igloo;

Describe(Fixed_tests) {
    It(Sample_cases) {
        Assert::That(repeat_str(3, "*"), Equals("***"));
        Assert::That(repeat_str(5, "#"), Equals("#####"));
        Assert::That(repeat_str(2, "ha "), Equals("ha ha "));
        Assert::That(repeat_str(5, ">"), Equals(">>>>>"));
        Assert::That(repeat_str(10, "!"), Equals("!!!!!!!!!!"));
        Assert::That(repeat_str(3, "hello "), Equals("hello hello hello "));
        Assert::That(repeat_str(3, "$"), Equals("$$$"));
        Assert::That(repeat_str(5, "a"), Equals("aaaaa"));
        Assert::That(repeat_str(6, "A"), Equals("AAAAAA"));
        Assert::That(repeat_str(7, "aA"), Equals("aAaAaAaAaAaAaA"));
        Assert::That(repeat_str(3, ""), Equals(""));
        Assert::That(repeat_str(0, "null"), Equals(""));
        Assert::That(repeat_str(0, ""), Equals(""));
    }
};

Describe(Random_tests) {

    std::string ref(size_t repeat, const std::string &str) {
        std::ostringstream os;
        std::fill_n(std::ostream_iterator<std::string>(os), repeat, str);
        return os.str();
    }

    void do_random_test() {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()[]{};:,.<>/? ";
        std::random_device engn;
        std::uniform_int_distribution<> symbol_pick(0, alphabet.size() - 1);
        std::uniform_int_distribution<> length_pick(0, 10);
        std::uniform_int_distribution<> num_pick(0, 100);
        size_t data_length = length_pick(engn);
        std::string data = "";
        for (size_t i = 0; i < data_length; i++) {
            data += alphabet[symbol_pick(engn)];
        }
        size_t repeat = num_pick(engn);
        std::string expected = ref(repeat, data);
        Assert::That(repeat_str(repeat, data), Equals(expected));
    }

    void run_random_tests() {
        for (size_t i = 0; i < 100; i++) {
            do_random_test();
        }
    }

    It(Random_cases) {
        run_random_tests();
    }
};
