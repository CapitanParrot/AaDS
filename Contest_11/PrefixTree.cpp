#include <iostream>
#include <string>
using std::string;
const int k = 256;

class Vertex {
public:
    Vertex** to; // нулевой указатель означает, что перехода нет
    bool terminal;
    Vertex() {
        terminal = 0;
        to = new Vertex * [k];
        for (size_t i = 0; i < k; i++)
        {
            to[i] = nullptr;
        }
    }
    ~Vertex() {
        delete[]to;
    }
};

class PrefixTrie {
private:
    Vertex* root;
public:
    ~PrefixTrie() {
        clear(root);

    }
    PrefixTrie() {
        root = new Vertex();
    }
    void clear(Vertex* node) {
        for (size_t i = 0; i < k; i++)
        {
            if (node->to[i] != nullptr) {
                clear(node->to[i]);
            }
        }
        delete node;
    }
    void add_string(string& s) {
        Vertex *v = root;
        for (char c : s) {
            if (!v->to[c])
                v->to[c] = new Vertex();
            v = v->to[c];
        }
        v->terminal = true;
    }
    bool find(string& s) {
        Vertex *v = root;
        for (char c : s) {
            
            if (!v->to[c])
                return false;
            v = v->to[c];
        }
        return v->terminal;
    }
};


int main()
{
    PrefixTrie pt;
    string str = "abc";
    pt.add_string(str);
    string str2 = "abcd";
    std::cout << pt.find(str2);
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
