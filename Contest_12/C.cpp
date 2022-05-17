#include <iostream>
#include <deque>
using std::cin;
using std::cout;
using std::deque;

bool compare(int first, int second) {
    if (first == 9 && second == 0) {
        return false;
    }
    return true;
}
int main() {
    deque<int> first;
    deque<int> second;

    for (size_t i = 0; i < 5; ++i) {
        int number;
        cin >> number;
        first.push_back(number);
    }
    for (size_t i = 0; i < 5; ++i) {
        int number;
        cin >> number;
        second.push_back(number);
    }
    int turn_counter = 0;
    bool winner = false;
    while (turn_counter < 1000000) {
        ++turn_counter;
        if ((first.front() > second.front()) && compare(first.front(), second.front()) ||
            (first.front() == 0 && second.front() == 9)) {
            first.push_back(first.front());
            first.pop_front();

            first.push_back(second.front());
            second.pop_front();
        } else {
            second.push_back(first.front());
            first.pop_front();

            second.push_back(second.front());
            second.pop_front();
        }
        if (first.empty()) {
            winner = false;
            break;
        }
        if (second.empty()) {
            winner = true;
            break;
        }
    }
    if (turn_counter == 1000000) {
        cout << "botva";
    } else {
        if (winner) {
            cout << "first " << turn_counter;
        } else {
            cout << "second " << turn_counter;
        }
    }
}
