#include <iostream>
using std::cin;
using std::cout;

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

    List() {
        first = nullptr;
        last = nullptr;
    }

    bool isEmpty() {
        return first == nullptr;
    }

    void pushBack(int val) {
        Node *p = new Node(val);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
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
    void insert(Node *p, int val) {
        Node *new_node = new Node(val);
        new_node->next = p->next;
        p->next = new_node;
    }

    void clear() {
        while (last != nullptr) {
            last = first->next;
            delete first;
            first = last;
        }
        delete last;
    }
};

void merge(List l1, List l2) {
    List merged;
    Node *cur1 = l1.first;
    Node *cur2 = l2.first;

    while (cur1 != nullptr || cur2 != nullptr) {
        if (cur1 == nullptr) {
            merged.pushBack(cur2->value);
            cur2 = cur2->next;
            continue;
        }
        if (cur2 == nullptr) {
            merged.pushBack(cur1->value);
            cur1 = cur1->next;
            continue;
        }
        if (cur1->value > cur2->value) {
            merged.pushBack(cur2->value);
            cur2 = cur2->next;
        } else {
            merged.pushBack(cur1->value);
            cur1 = cur1->next;
        }
    }
    merged.print();
    merged.clear();
}

int main() {
    int m, n;
    cin >> n >> m;

    List l1;
    List l2;
    List merged;
    int temp;
    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        l1.pushBack(temp);
    }

    for (size_t i = 0; i < m; i++) {
        cin >> temp;
        l2.pushBack(temp);
    }
    merge(l1, l2);
    l1.clear();
    l2.clear();
}
