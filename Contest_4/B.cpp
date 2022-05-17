#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;


int LengthOfString(vector<int> row) {
    int sum = 0;
    for (size_t i = 0; i < row.size(); i++) {
        sum += row[i];
    }
    sum += row.size();
    return sum;
}

string BuildRow(vector<int> oldRow, vector<int> newRow) {
    string row = "+";
    int LO = LengthOfString(oldRow), LN = LengthOfString(newRow);
    if (LO > LN) {
        for (size_t i = 0; i < LO; i++) {
            row += '-';
        }
    } else {
        for (size_t i = 0; i < LN; i++) {
            row += '-';
        }
    }
    int idx = 0;
    for (size_t i = 0; i < oldRow.size(); i++) {
        idx += 1 + oldRow[i];
        row.replace(idx, 1, "+");
    }
    idx = 0;
    for (size_t i = 0; i < newRow.size(); i++) {
        idx += 1 + newRow[i];
        row.replace(idx, 1, "+");
    }
    row += '\n';
    row += '|';

    for (size_t i = 0; i < newRow.size(); i++) {
        for (size_t j = 0; j < newRow[i]; j++) {
            row += ' ';
        }
        row += '|';
    }
    row += '\n';
    return row;
}

string BuildFloor(vector<int> row) {
    string floor = "+";
    for (size_t i = 0; i < row.size(); i++) {
        for (size_t j = 0; j < row[i]; j++) {
            floor += '-';
        }
        floor += '+';
    }
    return floor;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> tab(n, vector<int>());

    for (size_t i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> row(m);
        for (size_t j = 0; j < m; j++) {
            cin >> row[j];
        }
        tab[i] = row;
    }
    vector<int> a{};
    cout << BuildRow(a, tab[0]);

    for (size_t i = 1; i < n; i++) {
        cout << BuildRow(tab[i - 1], tab[i]);
    }
    cout << BuildFloor(tab[n - 1]);
}
