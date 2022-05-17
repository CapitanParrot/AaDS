#include <set>
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::multiset;
using std::setprecision;

int main() {
    multiset<int64_t> numbers;
    size_t numbers_count;
    cin >> numbers_count;
    for (size_t i = 0; i < numbers_count; ++i) {
        int64_t number;
        cin >> number;
        numbers.insert(number);
    }
    double cost = 0;
    while (numbers.size() > 1) {
        auto first = numbers.begin(), second = next(first), third = next(second);
        int64_t sum = *first + *second;
        numbers.erase(first, third);
        cost += sum;
        numbers.insert(sum);
    }
    cout << setprecision(2) << std::fixed << cost * 0.05;
}
