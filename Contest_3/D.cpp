#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int main() {
    int n, window;
    cin >> n >> window;

    vector<int64_t> min(n);
    for (int64_t i = 0; i < n; i++) {
        cin >> min[i];
    }
    for (int64_t len = 1; len < window; len *= 2) {
        int64_t shift;
        if (len * 2 <= window) {
            shift = len;
        } else {
            shift = window - len;
        }
        for (int64_t i = 0; i + shift < n; i++) {
            min[i] = std::min(min[i], min[i + shift]);
        }
    }
    for (size_t i = 0; i < n - window + 1; i++) {
        cout << min[i] << " ";
    }
}
