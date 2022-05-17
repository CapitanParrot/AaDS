#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void Fill(vector<vector<int64_t>>* arr, int n, int64_t a, int64_t d) {
    for (int diag = 0; diag < 2 * n; diag++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (diag + 1 == (i + 1) + (j + 1)) {
                    if (diag % 2) {
                        (*arr)[i][j] = a;
                    } else {
                        (*arr)[j][i] = a;
                    }
                    a += d;
                }
            }
        }
    }
}

void Output(vector<vector<int64_t>>* arr, int n) {
    // k - считает строки, j - считает столбцы
    int k = 0, j = 1, sum = 0;

    while (true) {
        if (k == j || j + k >= n - 1) {
            break;
        }
        sum += (*arr)[0 + k][j];
        sum += (*arr)[n - k - 1][j];

        if (j + 1 == n - 1 - k) {
            k += 1;
            j = k;
        }
        ++j;
    }
    cout << sum << "\n";
    if (n <= 20) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (*arr)[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
int main() {
    int n;
    cin >> n;
    int64_t a, d;
    cin >> a >> d;
    vector<vector<int64_t>> arr(n, vector<int64_t>(n));

    Fill(&arr, n, a, d);

    Output(&arr, n);
}
