#include <random>
#include "igloo/igloo_alt.h"
#include "square_n_sum.h"

using namespace igloo;

Describe(test_square_sum) {
    It(should_pass_some_basic_tests) {
        Assert::That(square_sum({1, 2}), Equals(5));
        Assert::That(square_sum({0, 3, 4, 5}), Equals(50));
        Assert::That(square_sum({}), Equals(0));
        Assert::That(square_sum({-1, -2}), Equals(5));
        Assert::That(square_sum({-1, 0, 1}), Equals(2));
    }

    It(should_pass_some_tests_with_random_data) {
        std::mt19937 engine{std::random_device{}()};
        std::uniform_int_distribution<> dist1{2, 10};
        std::uniform_int_distribution<> dist2{-20, 20};
        for (int i = 0; i < 40; ++i) {
            int size = dist1(engine);
            std::vector<int> numbers;
            numbers.reserve(size);
            std::generate_n(std::back_inserter(numbers), size, [&]() { return dist2(engine); });
            int expected = std::accumulate(numbers.begin(), numbers.end(), 0, [](int a, int b) { return a + b * b; });
            Assert::That(square_sum(numbers), Equals(expected));
        }
    }
};
