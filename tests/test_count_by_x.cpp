#include <vector>
#include <ctime>
#include <cstdlib>

#include "igloo/igloo_alt.h"
#include "006_count_by_x/count_by_x.h"

using namespace igloo;

Describe(Count_By_X) {
    std::vector<int> sol(int x, int n) {
        std::vector<int> temp;
        for (int i = 1; i <= n; i++)
            temp.push_back(i * x);
        return temp;
    }

    It(Basic_Tests) {
        std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Assert::That(countBy(1, 10), Equals(expected));
        expected = {2, 4, 6, 8, 10};
        Assert::That(countBy(2, 5), Equals(expected));
        expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Assert::That(countBy(1, 10), Equals(expected));
        expected = {100, 200, 300, 400, 500};
        Assert::That(countBy(100, 5), Equals(expected));
    }

    It(Random_Tests) {
        srand(time(0));
        for (int i = 0; i < 50; i++) {
            int x = rand() % 100 + 1;
            int n = rand() % 20 + 1;
            std::vector<int> expected = sol(x, n);
            Assert::That(countBy(x, n), Equals(expected));
        }
    }
};
