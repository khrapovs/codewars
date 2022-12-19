#include <ctime>
#include <cstdlib>
#include "igloo/igloo_alt.h"
#include "009_beginner_series_2_clock/beginner_series_2_clock.h"

using namespace igloo;

Describe(Clock) {
    It(BasicTests) {
        Assert::That(past(0, 1, 1), Equals(61000));
        Assert::That(past(1, 1, 1), Equals(3661000));
        Assert::That(past(0, 0, 0), Equals(0));
        Assert::That(past(1, 0, 1), Equals(3601000));
        Assert::That(past(1, 0, 0), Equals(3600000));
    }

    It(RandomTests) {
        std::srand(std::time(0));

        auto sol = [](int h, int m, int s) -> int {
            return (s + m * 60 + h * 3600) * 1000;
        };

        for (int i = 0; i < 100; i++) {
            int h = std::rand() % 24,
                    m = std::rand() % 60,
                    s = std::rand() % 60;
            Assert::That(past(h, m, s), Equals(sol(h, m, s)));
        }
    }
};
