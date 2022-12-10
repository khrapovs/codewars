#ifndef CODEWARS_SQUARE_N_SUM_H
#define CODEWARS_SQUARE_N_SUM_H

#include <vector>

using namespace std;

int square_sum(const vector<int>& numbers)
{
    int out {};
    for (int num: numbers)
        out += num*num;
    return out;
}

#endif //CODEWARS_SQUARE_N_SUM_H
