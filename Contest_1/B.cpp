// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;
double FastPow(double num, int deg) {
    if (deg == 0) {
        return 1;
    }
    if (deg % 2 == 0) {
        return FastPow(num * num, deg / 2);
    }
    return num * FastPow(num, deg - 1);
}
int main()
{
    double number;
    int degree;
    cin >> number >> degree;
    cout << fixed << setprecision(5) << FastPow(number, degree);
}

