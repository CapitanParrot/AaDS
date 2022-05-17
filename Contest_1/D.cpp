// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

bool Compare(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    if (Compare(str1, str2)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}
