#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::string;
class Deque {
 public:
    int* arr;
    int size;
    int head;
    int tail;

    Deque() {
        arr = new int[101];
        size = 0;
        head = 50;
        tail = 50;
    }
    void Push_front(int n) {
        head--;
        arr[(head - 1 + 101) % 101] = n;
        size++;
        cout << "ok" << '\n';
    }
    void Push_back(int n) {
        arr[(tail + 1) % 101] = n;
        tail++;
        size++;
        cout << "ok" << '\n';
    }
    int Pop_front() {
        if (head != tail) {
            head++;
            size--;
            return arr[(head - 1 + 101) % 101 - 1];
        } else {
            throw "error";
        }
    }
    int Pop_back() {
        if (head != tail) {
            tail--;
            size--;
            return arr[(tail + 1) % 101];
        } else {
            throw "error";
        }
    }
    int Front() {
        if (head != tail) {
            return arr[(head - 1 + 101) % 101];
        } else {
            throw "error";
        }
    }
    int Back() {
        if (head != tail) {
            return arr[(tail + 1) % 101 - 1];
        } else {
            throw "error";
        }
    }
    void Clear() {
        size = 0;
        tail = 50;
        head = 50;
        cout << "ok" << '\n';
    }
};

int main() {
    Deque deq;
    int n;
    string command;
    while (true) {
        cin >> command;
        if (command == "push_front") {
            cin >> n;
            deq.Push_front(n);
        }
        if (command == "push_back") {
            cin >> n;
            deq.Push_back(n);
        }
        try {
            if (command == "pop_front") {
                cout << deq.Pop_front() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "pop_back") {
                cout << deq.Pop_back() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "front") {
                cout << deq.Front() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "back") {
                cout << deq.Back() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        if (command == "size") {
            cout << deq.size << '\n';
        }
        if (command == "clear") {
            deq.Clear();
        }
        if (command == "exit") {
            delete[] deq.arr;
            cout << "bye" << '\n';
            break;
        }
    }
}
