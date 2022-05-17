#include <iostream>
#include <string>
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
    void insert(int pos, int val) {
        Node *new_node = new Node(val);
        Node *p = first;
        int i = 0;
        while (i < pos) {
            p = p->next;
            i++;
        }
        new_node->next = p->next;
        p->next = new_node;
    }

    void del(int pos) {
        Node *p = first;
        int i = 0;
        while (i < pos) {
            p = p->next;
            i++;
        }
        Node *temp = p->next;
        p->next = p->next->next;
        delete temp;
    }

    void clear() {
        while (last != nullptr) {
            last = first->next;
            delete first;
            first = last;
        }
        // delete last;
    }
    ~List() {
        clear();
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    List list;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list.pushBack(temp);
    }
    string command;
    for (size_t i = 0; i < m; i++) {
        cin >> command;
        if (command == "insert") {
            int val, pos;
            cin >> val >> pos;
            list.insert(pos, val);
        }
        if (command == "remove") {
            int pos;
            cin >> pos;
            list.del(pos);
        }
    }
    list.print();
    list.clear();
}
