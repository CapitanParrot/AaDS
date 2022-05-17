#include <iostream>
#include <string>
using std::cout;
using std::string;
class Stack {
 public:
    int top;
    int size;
    int capacity;
    int* arr;

    Stack() {
        top = -1;
        size = 0;
        capacity = 10;
        arr = new int[capacity];
    }
    void Push(int elem) {
        if (size == capacity) {
            Resize();
        }
        ++top;
        arr[top] = elem;
        ++size;
        cout << "ok" << '\n';
    }
    int Pop() {
        if (top != -1) {
            --size;
            return arr[top--];
        } else {
            throw "error";
        }
    }
    int Back() {
        if (top != -1) {
            return arr[top];
        } else {
            throw "error";
        }
    }
    void Clear() {
        top = -1;
        size = 0;
        cout << "ok" << '\n';
    }
    bool IsEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }
    void Resize() {
        int* copy = new int[capacity * 2];
        for (size_t i = 0; i < capacity; i++) {
            copy[i] = arr[i];
        }
        capacity *= 2;
        arr = copy;
    }
};

int main() {
    Stack stack;
    int n;
    string command;
    while (true) {
        std::cin >> command;
        if (command == "push") {
            std::cin >> n;
            stack.Push(n);
        }
        try {
            if (command == "back") {
                cout << stack.Back() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "pop") {
                cout << stack.Pop() << '\n';
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        if (command == "size") {
            cout << stack.size << '\n';
        }
        if (command == "clear") {
            stack.Clear();
        }
        if (command == "exit") {
            delete[] stack.arr;
            cout << "bye" << '\n';
            break;
        }
    }
}
