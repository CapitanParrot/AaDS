#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::to_string;

vector<int> ParseTime(string str) {
    vector<int> time;
    std::istringstream iss(str);
    while (!iss.eof()) {
        string temp;
        std::getline(iss, temp, ':');
        time.push_back(std::stoi(temp));
    }
    return time;
}

string SetTime(vector<int> mainTime, vector<int> timer) {
    string time = "";
    int days = 0;
    for (size_t i = 0; i < timer.size(); i++) {
        mainTime[mainTime.size() - 1 - i] += timer[timer.size() - 1 -i];
    }

    mainTime[1] += mainTime[2] / 60;
    mainTime[2] = mainTime[2] % 60;
    mainTime[0] += mainTime[1] / 60;
    mainTime[1] = mainTime[1] % 60;
    days += mainTime[0] / 24;
    mainTime[0] = mainTime[0] % 24;

    if (mainTime[0] < 10) {
        time += to_string(0);
    }
    time += to_string(mainTime[0]) + ":";

    if (mainTime[1] < 10) {
        time += to_string(0);
    }
    time += to_string(mainTime[1]) + ":";

    if (mainTime[2] < 10) {
        time += to_string(0);
    }

    time += to_string(mainTime[2]);
    if (days != 0) {
        time += "+" + to_string(days);
        time += " days";
    }
    return time;
}

int main() {
    string mainTimeStr, timerStr;
    cin >> mainTimeStr >> timerStr;
    vector<int> mainTime = ParseTime(mainTimeStr);
    vector<int> timer = ParseTime(timerStr);
    cout << SetTime(mainTime, timer);
}
