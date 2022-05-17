// F.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
int GCD(long long a, long long b, long& counter) {
	counter++;
	if (b == 0) {
		
		return abs(a);
	}
	else {
		
		GCD(b, a % b, counter);
	}
}

int main()
{
	long counter = 0, N;
	std::string inputFirst, inputSecond;
	long long gcdresult;
	bool flag = false;
	std::cin >> N;

	std::cin >> inputFirst;
	if (inputFirst.find('.') != -1 ) {
		std::cout << "Sequence has float values!";
		flag = true;
	}
	else {
		gcdresult = atoll(inputFirst.c_str());
		for (int i = 0; i < N - 1; i++)
		{
			std::cin >> inputSecond;
			if (inputSecond.find('.') != -1 ) {
				std::cout << "Sequence has float values!";
				flag = true;
				break;
			}
			gcdresult = GCD(atoll(inputSecond.c_str()), gcdresult,counter);
		}
	}
	if (!flag) {
		std::cout << gcdresult << " " << counter;
	}
	

	//std::cin >> inputSecond;
	//std::cout << atoi(inputFirst.c_str()) << " " << atoi(inputSecond.c_str());
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
