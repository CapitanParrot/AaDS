// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
int main()
{
    std::string upLetters = "QWERTYUIOPASDFGHJKLZXCVBNM", downLetters = "qwertyuiopasdfghjklzxcvbnm", digits = "1234567890";

    bool up = false, down = false, digit = false;

    std::string password;

    std::cin >> password;

    if (password.length() < 8) {
        std::cout << "NO";
    }
    else {
        for (int i = 0; i < upLetters.length(); i++)
        {
            if (password.find(upLetters[i]) != -1) {
                up = true;
            }
        }
        for (int i = 0; i < downLetters.length(); i++)
        {
            if (password.find(downLetters[i]) != -1) {
                down = true;
            }
        }
        for (int i = 0; i < digits.length(); i++)
        {
            if (password.find(digits[i]) != -1) {
                digit = true;
            }
        }
        if (up && down && digit) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
    }
}

