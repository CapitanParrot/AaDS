// B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
int BinSearchStep(std::vector<int> arr, int key) {
   
    int left = 0; 
    int right = arr.size()-1; 
    
    int steps = 0;
    int mid = 0;
    while (1)
    {
        steps++;
        mid = (left + right) / 2;

        if (key < arr[mid])       
            right = mid - 1;      
        else if (key > arr[mid])  
            left = mid + 1;    
        else                       
            break;           
        
        
    }
    /*while ((left <= right) && (flag != true)) {
        steps++;
        mid = (left + right) / 2; 

        if (arr[mid] == key) flag = true; 
        if (arr[mid] > key) right = mid - 1; 
        else left = mid + 1;
        
    }
    std::cout << mid;*/
    return steps;
}

int main()
{
    long long N, M = 1;
    int counter = 0;
    std::cin >> N;
    /*std::vector<int> arr(abs(N));
    
    for ( long long i = 0; i < N; i++)
    {
        if (i == 0) {
            arr[i] = 1;
        }
        else {
            arr[i] = 2;
        }
    }*/
    while (N > M) {
        M *= 2;
        counter++;
    }
    std::cout << counter;

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
