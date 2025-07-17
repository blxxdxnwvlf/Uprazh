#include <iostream>
#include <cctype>
#include <string>

// Функция для подсчета знаков препинания в строке
int countPunctuationMarks(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (ispunct(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::cout << "Введите строку для подсчета знаков препинания: ";
    std::getline(std::cin, input);

    int punctuationCount = countPunctuationMarks(input);
    std::cout << "Количество знаков препинания в строке: " << punctuationCount << std::endl;

    return 0;
}