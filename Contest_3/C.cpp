// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::vector;

int amountNumbers;
vector<int> tree;

void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
        if (a[tl] == 0) {
            tree[v] = 1;
        } else {
            tree[v] = 0;
        }
    } else {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int sum2(int a, int b) {
    a += amountNumbers;
    b += amountNumbers;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            s += tree[a];
        }
        if (b % 2 == 0) {
            s += tree[b];
        }

        a = (a + 1) / 2;
        b = (b - 1) / 2;
    }
    return s;
}

int get_sum(int l, int r, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        return tree[v];
    }

    if (tr < l || r < tl) {
        return 0;
    }

    int tm = (tl + tr) / 2;
    return get_sum(l, r, v * 2, tl, tm)
        + get_sum(l, r, v * 2 + 1, tm + 1, tr);
}

int main() {
    cin >> amountNumbers;
    std::vector<int> numbers(amountNumbers);

    tree.resize(amountNumbers * 4);

    for (int i = 0; i < amountNumbers; i++) {
        int number;
        cin >> number;
        numbers[i] = number;
    }

    build(numbers, 1, 0, amountNumbers - 1);

    int amountRequests;
    cin >> amountRequests;

    for (int i = 0; i < amountRequests; i++) {
        int left, right;
        cin >> left >> right;
        // cout << sum2(left, right) << " ";
        cout << get_sum(left - 1, right - 1, 1, 0, amountNumbers - 1) << " ";
    }
}
