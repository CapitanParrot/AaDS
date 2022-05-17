// D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

bool Check(std::string str) {
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+') {
            counter++;
        }
    }
    if (counter > 1 || counter < 1) {
        return false;
    }
    return true;
}

int main()
{
    int N, M;
    int paperCounter = 0;
    std::cin >> N >> M;
    std::vector<int> parties(N);

    std::string vote;
    for (int i = 0; i < M; i++)
    {
        std::cin >> vote;
        if (Check(vote)) {
            paperCounter++;
            for (int i = 0; i < vote.length(); i++)
            {
                if (vote[i] == '+') {
                    parties[i]++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if ((float)parties[i] / paperCounter * 100 >= 7) {
            std::cout  << i + 1 << " ";
        }
    }
}
