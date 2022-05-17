// E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

void RecRev(int n) {
	if (n < 1) {

	}
	else {
		int number;
		cin >> number;
		RecRev(n - 1);
		cout << number << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	RecRev(n);

}

