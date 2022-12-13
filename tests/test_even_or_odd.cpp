#include "igloo/igloo_alt.h"
#include "004_even_or_odd/even_or_odd.h"

#include <random>
#include <string>

using namespace igloo;

Describe(even_or_odd_method) {
    It(basic_tests) {
        Assert::That(even_or_odd(2), Equals("Even"));
        Assert::That(even_or_odd(1), Equals("Odd"));
        Assert::That(even_or_odd(0), Equals("Even"));
        Assert::That(even_or_odd(7), Equals("Odd"));
        Assert::That(even_or_odd(-1), Equals("Odd"));
    }

    It(additional_tests) {
        Assert::That(even_or_odd(1545452), Equals("Even"));
        Assert::That(even_or_odd(17), Equals("Odd"));
        Assert::That(even_or_odd(78), Equals("Even"));
        Assert::That(even_or_odd(74156741), Equals("Odd"));
        Assert::That(even_or_odd(-123), Equals("Odd"));
        Assert::That(even_or_odd(-456), Equals("Even"));
    }

    std::string refe(int n) {
        return n % 2 ? "Odd" : "Even";
    }

    int generate_random_num() {
        std::random_device engn;
        std::uniform_int_distribution<> d_pick(-1000, 1000000);
        int d = d_pick(engn);
        return d;
    }

    It(Random_tests) {
        for (size_t i = 0; i < 100; i++) {
            int d = generate_random_num();
            std::string expected = refe(d);
            Assert::That(even_or_odd(d), Equals(expected));
        }
    }
};
