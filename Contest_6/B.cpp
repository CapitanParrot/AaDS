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

void reverse(Node *n) {
    if (n != nullptr) {
        reverse(n->next);
        cout << n->value << " ";
    }
}
int main() {
    List list;
    int n;
    cin >> n;
    int temp;
    for (size_t i = 0; i < n; i++) {
        cin >> temp;
        list.pushBack(temp);
    }
    reverse(list.first);
    list.clear();
}
