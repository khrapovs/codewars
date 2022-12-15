#include "count_by_x.h"

#include <vector>

using namespace std;

vector<int> countBy(int x, int n) {
    vector<int> out = {};
    for (int i = 1; i <= n; ++i) {
        out.push_back(i * x);
    }
    return out;
}
