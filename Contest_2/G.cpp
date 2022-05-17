// G.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

long long GCD(long long a, long long b) {
	
	if (b == 0) {

		return abs(a);
	}
	else {

		GCD(b, a % b);
	}
}
long long ICM(long long a, long long b) {
	return a / GCD(a, b) * b;
}
int main()
{
	long counter = 0, N;
	std::string inputFirst, inputSecond;
	long long icmresult;
	bool flag = false;
	std::cin >> N;

	std::cin >> inputFirst;
	if (inputFirst.find('.') != -1) {
		std::cout << "Sequence has float values!";
		flag = true;
	}
	else {
		icmresult = atoll(inputFirst.c_str());
		for (int i = 0; i < N - 1; i++)
		{
			std::cin >> inputSecond;
			if (inputSecond.find('.') != -1) {
				std::cout << "Sequence has float values!";
				flag = true;
				break;
			}
			icmresult = ICM(atoll(inputSecond.c_str()), icmresult);
		}
	}
	if (!flag) {
		std::cout << abs(icmresult);
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
