#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {
    int64_t n, m;
    cin >> n >> m;

    vector<vector<int64_t>> triangle(n, vector<int64_t>(m));

    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < m; j++) {
            if (i == 0 || j == 0) {
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = triangle[i - 1][j] + triangle[i][j - 1];
            }
            cout << triangle[i][j] << " ";
        }
        cout << "\n";
    }
}
