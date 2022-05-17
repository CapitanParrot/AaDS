#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::sort;
using std::vector;

class MinimalSet {
public:
    vector<int> set;
    int next_result = -1;
    bool is_previous_next = false;
    const int Billion = 1000000000;
    void add(int number) {
        if (is_previous_next) {
            set.push_back((number + next_result) % Billion);
            sort(set.begin(), set.end());
        } else {
            set.push_back(number);
            sort(set.begin(), set.end());
        }
        is_previous_next = false;
    }

    int next(int number) {
        int result = -1;
        for (auto i = set.begin(); i != set.end(); ++i) {
            if (*i >= number) {
                result = *i;
                break;
            }
        }
        next_result = result;
        is_previous_next = true;
        return result;
    }
};

int main() {
    MinimalSet min_set;
    int comands;
    cin >> comands;
    for (int i = 0; i < comands; ++i) {
        char next_comand;
        int number;
        cin >> next_comand;
        cin >> number;
        if (next_comand == '+') {
            min_set.add(number);
        } else {
            cout << min_set.next(number) << '\n';
        }
    }
}
