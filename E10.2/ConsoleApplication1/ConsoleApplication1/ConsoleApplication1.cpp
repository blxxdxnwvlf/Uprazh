#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Функция для замены одиночных пробелов на пять пробелов
std::string replaceSpaces(const std::string& line) {
    std::stringstream result;
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            // Проверяем, что это одиночный пробел (не подряд идущие)
            if (i == 0 || line[i - 1] != ' ') {
                result << "     "; // 5 пробелов
            }
        }
        else {
            result << line[i];
        }
    }
    return result.str();
}

int main() {
    setlocale(LC_ALL, "Russian");
    const std::string inputFile = "F1.txt";
    const std::string outputFile = "F2.txt";

    // Открываем файлы
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        std::cerr << "Не удалось открыть файл " << inputFile << std::endl;
        return 1;
    }

    if (!outFile.is_open()) {
        std::cerr << "Не удалось открыть файл " << outputFile << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::string transformedLine = replaceSpaces(line);
        outFile << transformedLine << std::endl;
    }

    // Закрываем файлы
    inFile.close();
    outFile.close();

    std::cout << "Преобразование завершено. Результат записан в " << outputFile << std::endl;

    return 0;
}