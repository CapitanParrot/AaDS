#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main() {
    string encrypted;

    cin >> encrypted;
    encrypted = encrypted.erase(encrypted.length() - 1, 1);
    vector<string> vect(encrypted.length());
    int n = 0, m = 0;
    for (size_t i = 0; i < encrypted.length(); i++) {
        if (i % 2 == 0) {
            vect[n] = encrypted[i];
            ++n;
        } else {
            vect[vect.size() - m - 1] = encrypted[i];
            ++m;
        }
    }
    for (size_t i = 0; i < vect.size(); i++) {
        cout << vect[i];
    }
}
