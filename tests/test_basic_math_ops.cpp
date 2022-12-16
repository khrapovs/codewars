#include "igloo/igloo_alt.h"
#include "007_basic_math_ops/basic_math_ops.h"

using namespace igloo;

Describe(basic_op) {
    It(basic_tests) {
        AssertThat(basicOp('+', 5, 4), Equals(9));
        AssertThat(basicOp('-', 11, 8), Equals(3));
        AssertThat(basicOp('*', 3, 4), Equals(12));
        AssertThat(basicOp('/', 16, 4), Equals(4));
    };

    It(random_tests) {
        srand(time(0));
        for (int i = 0; i < 10; i++) {
            int n1 = rand() % 1000, n2 = rand() % 1000;
            AssertThat(basicOp('+', n1, n2), Equals(n1 + n2));
        }
        for (int i = 0; i < 10; i++) {
            int n1 = rand() % 1000, n2 = rand() % 1000;
            AssertThat(basicOp('-', n1, n2), Equals(n1 - n2));
        }
        for (int i = 0; i < 10; i++) {
            int n1 = rand() % 1000, n2 = rand() % 1000;
            AssertThat(basicOp('*', n1, n2), Equals(n1 * n2));
        }
        for (int i = 0; i < 10; i++) {
            int n1 = rand() % 1000, n2 = rand() % 1000;
            AssertThat(basicOp('/', n1, n2), Equals(n1 / n2));
        }
    };
};
