#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;
using std::stack;
using std::vector;

int main() {
    int number;
    cin >> number;
    stack<int> cities;
    vector<int> prices(number);
    vector<int> result;
    result.resize(number, -1);

    for (int i = 0; i < number; ++i) {
        cin >> prices[i];
    }

    for (size_t i = 0; i < number; ++i) {
        while (!cities.empty() && prices[cities.top()] > prices[i]) {
            result[cities.top()] = i;
            cities.pop();
        }
        cities.push(i);
    }

    for (size_t i = 0; i < number; ++i) {
        cout << result[i] << " ";
    }
}
