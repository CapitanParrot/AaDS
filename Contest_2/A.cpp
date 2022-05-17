// A.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstdlib>

// Смотрю на слово слева и справа, сравниваю согласные буквы по порядку, если две согласные не равны возвращаю false
// Если все сравнения прошли возвращаю true;
bool ConstantPalindrome(std::string word) {
    std::string consonantLetters = "wrtpsdfghjklzxcvbnm";
    int j = word.length() - 1;
    
    for (int i = 0; i < word.length(); i++)
    {
        
        if (consonantLetters.find(word[i]) != -1 && j >= i) {
            
            while (j >= i) {
                if (consonantLetters.find(word[j]) != -1) {
                    if (word[i] != word[j]) {
                        return false;
                    }
                    j--;
                    break;
                }
                j--;
            }
        }
    }
    return true;
}

int main()
{
    
    std::string word, consonantLetters = "wrtpsdfghjklzxcvbnm";
    std::cin >> word;
    if (ConstantPalindrome(word)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }

}

