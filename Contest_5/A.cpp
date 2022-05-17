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
        arr[head] = n;
        size++;
        cout << "ok" << '\n';
    }
    void Push_back(int n) {
        arr[tail] = n;
        tail++;
        size++;
        cout << "ok" << '\n';
    }
    int Pop_front() {
        if (head != tail) {
            head++;
            size--;
            return arr[head - 1];
        }
        else {
            throw "error";
        }
    }
    int Pop_back() {
        if (head != tail) {
            tail--;
            size--;
            return arr[tail];
        }
        else {
            throw "error";
        }
    }
    int Front() {
        if (head != tail) {
            return arr[head];
        }
        else {
            throw "error";
        }
    }
    int Back() {
        if (head != tail) {
            return arr[tail];
        }
        else {
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

int main()
{
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
                cout << deq.Pop_front();
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "pop_back") {
                cout << deq.Pop_back();
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "front") {
                cout << deq.Front();
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        try {
            if (command == "back") {
                cout << deq.Back();
            }
        }
        catch (const char* ms) {
            cout << ms << '\n';
        }
        if (command == "size") {
            cout << deq.size;
        }
        if (command == "clear") {
            deq.Clear();
        }
        if (command == "exit") {
            delete[] deq.arr;
            break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
