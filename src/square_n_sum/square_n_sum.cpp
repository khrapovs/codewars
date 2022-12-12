#include <vector>
#include "square_n_sum.h"

using namespace std;

int square_sum(const vector<int> &numbers) {
    int out{};
    for (int num: numbers)
        out += num * num;
    return out;
}
