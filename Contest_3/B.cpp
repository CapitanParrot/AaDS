#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

bool IsAllEven(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1) {
            return false;
        }
    }
    return true;
}


void DivisionBy2(vector<int>* arr) {
    for (size_t i = 0; i < (*arr).size(); i++) {
        (*arr)[i] /= 2;
    }
}

int Operations(vector<int>* arr, int n) {
    int operationCounter = 0;

    while (true) {
        int zeroCounter = 0;
        int i;
        for (i = 0; i < n; i++) {
            if ((*arr)[i] % 2 == 1 || (*arr)[i] % 2 == -1) {
                break;
            }
            if ((*arr)[i] == 0) {
                ++zeroCounter;
            }
        }

        if (zeroCounter == n) {
            return operationCounter;
        }

        if (i == n) {
            DivisionBy2(arr);
            ++operationCounter;
        }


        for (int j = i; j < n; j++) {
            if ((*arr)[j] % 2 == 1 || (*arr)[i] % 2 == -1) {
                if ((*arr)[j] > 0) {
                    --(*arr)[j];
                } else {
                    ++(*arr)[j];
                }
                ++operationCounter;
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << Operations(&arr, n);
}
