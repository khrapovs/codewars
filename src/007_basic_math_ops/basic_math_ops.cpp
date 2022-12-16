#include <iostream>
#include "basic_math_ops.h"

using namespace std;

int basicOp(char op, int val1, int val2) {
    switch (op) {
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            return val2 != 0 ? val1 / val2 : 0;
        default:
            cout << "Unrecognised operator " << op << endl;
            return 0;
    }
}
