#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

string FindSequence(string x, int N) {
    char c[26][3000] = {};
    for (size_t i = 0; i < x.length(); i++) {
        c[0][i] = x[i];
    }
    int k, n;
    for (int i = 0; i < N; i++) {
        k = 0;
        n = 0;
        for (int j = 0; c[i][j] != '\0'; j++) {
            k++;
            if (c[i][j + 1] != c[i][j]) {
                c[i + 1][n] = k + 48;
                c[i + 1][n + 1] = c[i][j];
                n += 2;
                k = 0;
            }
        }
    }
    string test = c[N - 1];
    return test;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    string x;
    cin >> x >> N;
    cout << FindSequence(x, N) << "\n";
}
