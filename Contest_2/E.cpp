// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>

int main()
{
    std::string first, second, temp;
    std::cin >> first >> second;
    long N, M;
    
    std::cin >> N >> M;

    for (int i = 2; i < N; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }
    std::cout << second[M-1];
}

