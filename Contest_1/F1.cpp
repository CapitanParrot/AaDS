// F1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
void SinMac(double x, double eps,int accuracy) {
    double pi = 3.14159265;
    double factorial = 1.0;
    
    while (x > pi / 2 || x < -pi / 2) {
        if (x > pi / 2) {
            x = pi - x;
        }
        else {
            x += pi * 2;
        }
    }
    
    
    double sum = 0;
    double arg = x;
    double next = x;
    long long i = 1;
    int sign = 1;
    long long counter = 0;
    
    
    do {
        sum += next;
        arg *= x * x;
        factorial *= (i + 1) * (i + 2);
        sign *= -1;
        i += 2;
        next = sign * arg / factorial;
        
        counter++;
    } while (fabs(next) >= eps);
    if (sum == 0) {
        cout << sum << '\n';
    }
    else {
        cout << fixed << setprecision(accuracy) << sum << '\n';

    }
    cout << counter;
}

int main()
{
    double x;
    cin >> x;
    string eps;
    cin >> eps;
    int acc = 0;
    bool flag = false;
    for (int i = 0; i < eps.length(); i++)
    {
        if (flag) {
            acc++;
        }
        if (eps[i] == '.') {
            flag = true;
        }
        
    }
    SinMac(x, atof(eps.c_str()), acc);//eps.length() - 2
}

