#include "iostream"
#include <vector>
#include "square_n_sum.h"

using namespace std;

int main() {
    vector<int> numbers = {1, 3, 4};
    int result = square_sum(numbers);
    for (int number: numbers) {
        cout << number << endl;
    }
    cout << result;
    return 0;
}
