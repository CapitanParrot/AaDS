#include <iostream>
#include <string>
#include <cmath>
using std::abs;
using std::cin;
using std::cout;
using std::string;
class Node {
public:
    int value;
    Node *next;

    explicit Node(int val) {
        value = val;
        next = nullptr;
    }
};

class List {
public:
    Node *first;
    Node *last;
    int size;

    List() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return first == nullptr;
    }

    void pushBack(int val) {
        Node *p = new Node(val);
        if (isEmpty()) {
            first = p;
            last = p;
            size++;
            return;
        }
        last->next = p;
        last = p;
        size++;
    }

    void print() {
        if (isEmpty()) {
            return;
        }
        Node *p = first;

        while (p) {
            cout << p->value << " ";
            p = p->next;
        }
    }
    void insert(int pos, int val) {
        Node *new_node = new Node(val);
        Node *p = first;
        int i = 1;
        if (pos == 1) {
            new_node->next = first;
            first = new_node;
            size++;
            return;
        }
        while (i < pos - 1) {
            p = p->next;
            i++;
        }
        new_node->next = p->next;
        p->next = new_node;
        size++;
    }

    void del(int pos) {
        Node *p = first;
        int i = 1;
        if (pos == 1) {
            first = p->next;
            delete p;
            size--;
            return;
        }
        while (i < pos - 1) {
            p = p->next;
            i++;
        }
        Node *temp = p->next;
        p->next = p->next->next;
        delete temp;
        size--;
    }

    void clear() {
        while (last != nullptr) {
            last = first->next;
            delete first;
            first = last;
        }
        delete last;
    }

    void change(int i, int x) {
        Node *p = first;
        int k = 1;
        while (k < i) {
            p = p->next;
            k++;
        }
        p->value = x;
    }

    int at(int i) {
        Node *p = first;
        int k = 1;
        while (k < i) {
            p = p->next;
            k++;
        }
        return p->value;
    }
    int computeMod(int left, int right, int m) {
        Node *p = first;
        int i = 1;
        int64_t answer = 0;
        while (i < left) {
            p = p->next;
            i++;
        }
        while (i < right + 1) {
            answer += p->value;
            p = p->next;
            i++;
        }
        answer = answer % m;
        if (answer < 0) {
            answer += m;
        }
        return answer;
    }

    int computeXor(int left, int right) {
        Node *p = first;
        int i = 1;
        int64_t answer = 0;
        while (i < left) {
            p = p->next;
            i++;
        }
        while (i < right + 1) {
            answer ^= p->value;
            p = p->next;
            i++;
        }
        return answer;
    }
};
int main() {
    bool flag;
    int mod;
    string op;
    cin >> op;
    if (op == "+") {
        flag = true;
        cin >> mod;
    } else {
        flag = false;
    }

    int n;
    List list;
    cin >> n;
    for (int64_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list.pushBack(temp);
    }
    int q;
    cin >> q;
    string command;
    for (int64_t i = 0; i < q; i++) {
        cin >> command;
        if (command == "insert") {
            int i, x;
            cin >> i >> x;
            list.insert(i, x);
        }
        if (command == "erase") {
            int i;
            cin >> i;
            list.del(i);
        }
        if (command == "change") {
            int i, x;
            cin >> i >> x;
            list.change(i, x);
        }
        if (command == "at") {
            int i;
            cin >> i;
            cout << list.at(i) << '\n';
        }
        if (command == "compute") {
            int left, right;
            cin >> left >> right;
            if (flag) {
                cout << list.computeMod(left, right, mod) << '\n';
            } else {
                cout << list.computeXor(left, right) << '\n';
            }
        }
        if (command == "size") {
            cout << list.size << '\n';
        }
    }
    list.clear();
}
