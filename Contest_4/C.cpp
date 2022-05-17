#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::vector;

vector<string> Cut(string str) {
    vector<string> vecStr;
    string word;
    std::stringstream s(str);
    while (s >> word) {
        vecStr.push_back(word);
    }
    return vecStr;
}

int main() {
    string counterStr, playersStr;
    std::getline(cin, counterStr);
    std::getline(cin, playersStr);

    vector<string> counter = Cut(counterStr);
    vector<string> players = Cut(playersStr);
    int idx = counter.size() % players.size() - 1;
    if (idx == -1) {
        idx = players.size() - 1;
    }
    cout << players[idx];
}
