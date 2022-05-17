#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::map;

string GetDiff(string str1, string str2) {
    string answer = "";
    map <char, int> m1 = { {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0},
                             {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
                             {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
                             {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
                             {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0} };
    map <char, int> m2 = { {'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0},
                             {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0},
                             {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0},
                             {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
                             {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0} };

    for (size_t i = 0; i < str1.length(); i++) {
        if (str1[i] != ' ') {
            m1[str1[i]] += 1;
        }
    }

    for (size_t i = 0; i < str2.length(); i++) {
        if (str2[i] != ' ') {
            m2[str2[i]] += 1;
        }
    }
    auto it2 = m2.begin();
    for (auto& it1 : m1) {
        if (it1.second != 0 && it2->second == 0 || it1.second == 0 && it2->second != 0) {
            answer += it1.first;
            answer += " ";
        }
        ++it2;
    }
    if (answer == "") {
        answer = "NONE";
    }
    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string str1, str2;
    std::getline(cin, str1);
    std::getline(cin, str2);

    cout << GetDiff(str1, str2);
}
