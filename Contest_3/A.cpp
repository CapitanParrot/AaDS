#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using std::cout;
using std::cin;
using std::vector;
using std::map;

int CountDH(const vector<int64_t>& a, const vector<int64_t>& b) {
    int dh = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            ++dh;
        }
    }
    return dh;
}

vector<int64_t> ShiftOne(const vector<int64_t>& a) {
    vector<int64_t> b(a.size());
    b[0] = a[a.size() - 1];
    for (size_t i = 0; i < a.size() - 1; i++) {
        b[i + 1] = a[i];
    }
    return b;
}

bool Contains(map<int, vector<int64_t>>* a, vector<int64_t> b) {
    for (map<int, vector<int64_t>>::iterator i = (*a).begin(); i != (*a).end(); i++) {
        if (i->second == b) {
            return true;
        }
    }
    return false;
}

void Print(const vector<int64_t>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i == a.size() - 1) {
            cout << a[i] << "; ";
        } else {
            cout << a[i] << " ";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int64_t> arr(n);

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxDH = 0;
    map<int, vector<int64_t>> shifts;
    vector<int64_t> shiftedArr = arr;

    for (size_t i = 0; i < n; i++) {
        shiftedArr = ShiftOne(shiftedArr);
        int dh = CountDH(arr, shiftedArr);
        if (dh > maxDH) {
            maxDH = dh;
        }
    }
    shiftedArr = arr;
    int shiftCounter = 0;
    for (size_t i = 0; i < n; i++) {
        int dh = CountDH(arr, shiftedArr);
        if (dh == maxDH) {
            if (!Contains(&shifts, shiftedArr)) {
                shifts[shiftCounter] = shiftedArr;
            }
        }
        shiftedArr = ShiftOne(shiftedArr);
        ++shiftCounter;
    }
    cout << maxDH << "\n";
    for (auto i = shifts.begin(); i != shifts.end(); ++i) {
        Print(i->second);
        cout << i->first << "\n";
    }
}
