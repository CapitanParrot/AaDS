#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int64_t>> matrix(n, vector<int64_t>(m));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << m << " " << n << "\n";
    for (size_t j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
