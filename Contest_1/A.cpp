// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int  counter = 0, number;
	double mass = 0.0;
	while(true) {
		cin >> number;
		if (number == 0) {
			break;
		}
		mass += number;
		counter++;
	}

	cout<< fixed << std::setprecision(5)<< mass/counter;

}


