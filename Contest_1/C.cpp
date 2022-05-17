// C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;
int Reverse(int number) {
    int rev = 0;
    while (number != 0) {
        rev += number % 10;
        number /= 10;
        if (number != 0) {
            rev *= 10;
        }
    }
    return rev;
}
int main()
{
    int k, counter = 0;
    cin >> k;

    for (int i = 1; i < k + 1; i++)
    {
        
        if (Reverse(i) == i) {
            counter++;
        }
    }
    cout << counter;
}

