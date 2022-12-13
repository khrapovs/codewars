#include "igloo/igloo_alt.h"
#include "002_multiply/multiply.h"

using namespace igloo;

Describe(multiply_method) {
    It(should_handle_basic_tests) {
        Assert::That(multiply(1, 2), Equals(2));
        Assert::That(multiply(3, 4), Equals(12));
        Assert::That(multiply(5, 6), Equals(30));
        Assert::That(multiply(-1, 20), Equals(-20));
    }
};