#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Stack {
 public:
    int top;
    int size;
    int capacity;
    char* arr;

    Stack() {
        top = -1;
        size = 0;
        capacity = 10;
        arr = new char[capacity];
    }
    void Push(char elem) {
        if (size == capacity) {
            Resize();
        }
        ++top;
        arr[top] = elem;
        ++size;
    }
    char Pop() {
        if (top != -1) {
            --size;
            return arr[top--];
        } else {
            throw "error";
        }
    }
    char Back() {
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
        char* copy = new char[capacity * 2];
        for (size_t i = 0; i < capacity; i++) {
            copy[i] = arr[i];
        }
        capacity *= 2;
        arr = copy;
    }
};
int main() {
    bool flag = true;
    Stack stack;
    string seq;
    cin >> seq;
    for (size_t i = 0; i < seq.size(); i++) {
        if (seq[i] == '(' || seq[i] == '{' || seq[i] == '[') {
            stack.Push(seq[i]);
        }
        if (seq[i] == ')') {
            try {
                if (stack.Back() == '(') {
                    stack.Pop();
                } else {
                    flag = false;
                    break;
                }
            }
            catch (const char* ms) {
                flag = false;
                break;
            }
        }
        if (seq[i] == '}') {
            try {
                if (stack.Back() == '{') {
                    stack.Pop();
                } else {
                    flag = false;
                    break;
                }
            }
            catch (const char* ms) {
                flag = false;
                break;
            }
        }
        if (seq[i] == ']') {
            try {
                if (stack.Back() == '[') {
                    stack.Pop();
                } else {
                    flag = false;
                    break;
                }
            }
            catch (const char* ms) {
                flag = false;
                break;
            }
        }
    }
    try {
        if (stack.Back() == ')' || stack.Back() == '(' || stack.Back() == '}' ||
            stack.Back() == '{' || stack.Back() == ']' || stack.Back() == '[') {
            flag = false;
        }
    }
    catch (const char* ms) {
    }
    if (flag) {
        cout << "yes";
    } else {
        cout << "no";
    }
}
