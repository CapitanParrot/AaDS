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
        Vertex* v = root;
        for (char c : s) {
            if (!v->to[c])
                v->to[c] = new Vertex();
            v = v->to[c];
        }
        v->terminal = true;
    }
    bool find(string& s) {
        Vertex* v = root;
        for (char c : s) {

            if (!v->to[c])
                return false;
            v = v->to[c];
        }
        return v->terminal;
    }
};
// основной класс фильтра
class BloomFilter {
private:
    size_t number_of_hashes;
    size_t number_of_bits;
    size_t false_positives;
    PrefixTrie trie;
    bool* m_bits;
public:
    BloomFilter(size_t hashes, size_t bits) {
        number_of_hashes = hashes;
        number_of_bits = bits;
        false_positives = 0;
        m_bits = new bool[bits];
    }

    ~BloomFilter();

    // вставка информации об объекте
    void add(const std::string& obj) {
        //std::hash<std::string>;
        auto hash0 = std::hash<std::string>{}("abcd");
        auto tt = hash0 / number_of_bits;
        for (size_t i = 0; i < number_of_hashes; i++)
        {
            if (i == 0) {
                m_bits[std::hash<std::string>{}(obj) % number_of_bits] = true;
            }
            else {
                std::string str = obj;
                str.append(std::to_string(i));
                m_bits[std::hash<std::string>{}(str) % number_of_bits] = true;
            }
            trie.add_string(obj);
        }
    }

    // проверка принадлежности объекта
    bool verify(const std::string& obj);

    // считаем относительную величину false positive rate по запросам тестирования
    // принадлежности
    double getFPRate() const;

    size_t numberOfHashFunctions() {
        return number_of_hashes;
    }
    size_t numberOfBits() {
        return number_of_bits;
    }
};

int main()
{
    auto hash0 = std::hash<std::string>{}("abcd");
    
    auto tt = hash0 % 8;
    std::string ss = "abcd";
    int aa = 1;
    ss.append(std::to_string(aa));
    std::cout << hash0 << '\n' << tt << '\n' << ss;
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
