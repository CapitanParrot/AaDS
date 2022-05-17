#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    int amountNumbers;
    cin >> amountNumbers;
    vector<int> prefSum(amountNumbers + 1);
    int zeroCounter = 0;
    for (size_t i = 1; i < amountNumbers + 1; i++) {
        int number;
        cin >> number;
        if (number == 0) {
            ++zeroCounter;
        }
        prefSum[i] = zeroCounter;
    }

    int amountRequests;
    cin >> amountRequests;
    int left, right;
    for (size_t i = 0; i < amountRequests; i++) {
        cin >> left >> right;

        cout << prefSum[right] - prefSum[left - 1] << " ";
    }
}
