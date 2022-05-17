#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
struct Node {
    int value;
    Node *prev;
    Node *next;
};

class DList {
public:
    Node *head;
    Node *tail;
    int count;

    DList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    void pushFront(int val) {
        Node *temp = new Node;

        temp->prev = nullptr;
        temp->value = val;
        temp->next = head;

        if (head != nullptr) {
            head->prev = temp;
        }
        if (count == 0) {
            head = temp;
            tail = temp;
        } else {
            head = temp;
        }
        count++;
    }

    void pushBack(int val) {
        Node *temp = new Node;
        temp->next = nullptr;
        temp->value = val;
        temp->prev = tail;

        if (tail != nullptr) {
            tail->next = temp;
        }

        if (count == 0) {
            head = temp;
            tail = temp;
        } else {
            tail = temp;
        }
        count++;
    }

    void insert(int val, int pos) {
        if (pos == count + 1) {
            pushBack(val);
            return;
        } else if (pos == 1) {
            pushFront(val);
        }
        int i = 1;
        Node *ins = head;
        while (i < pos) {
            ins = ins->next;
            i++;
        }

        Node *prev_ins = ins->prev;
        Node *temp = new Node;
        temp->value = val;

        if (prev_ins != nullptr && count != 1) {
            prev_ins->next = temp;
        }

        temp->next = ins;
        temp->prev = prev_ins;
        ins->prev = temp;

        count++;
    }

    void del(int pos) {
        int i = 1;
        Node *del = head;

        while (i < pos) {
            del = del->next;
            i++;
        }

        Node *prev_del = del->prev;
        Node *after_del = del->next;

        if (prev_del != nullptr && count != 1) {
            prev_del->next = after_del;
        }
        if (after_del != nullptr && count != 1) {
            after_del->prev = prev_del;
        }
        if (pos == 1) {
            head = after_del;
        }
        if (pos == count) {
            tail = prev_del;
        }

        delete del;
        count--;
    }

    void delAll() {
        while (count != 0) {
            del(1);
        }
    }

    void printForward() {
        Node *p = head;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }

    void printBackward() {
        Node *p = tail;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->prev;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DList list;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        list.pushBack(temp);
    }
    string command;
    for (size_t i = 0; i < m; i++) {
        cin >> command;
        if (command == "push_front") {
            int val;
            cin >> val;
            list.pushFront(val);
        }
        if (command == "push_back") {
            int val;
            cin >> val;
            list.pushBack(val);
        }
        if (command == "insert") {
            int val, pos;
            cin >> val >> pos;
            list.insert(val, pos + 2);
        }
        if (command == "remove") {
            int pos;
            cin >> pos;
            list.del(pos + 2);
        }
    }
    list.printForward();
    cout << '\n';
    list.printBackward();
    list.delAll();
}
