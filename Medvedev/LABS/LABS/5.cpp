#include <iostream>
#include <fstream> // Для работы с файлами
#include <string>  // Для std::string
#include <vector>  // Необязательно, но может быть полезно

std::string processStringWithSpaces(const std::string& line) {
    std::string result = "";
    int i = 0;
    while (i < line.length()) {
        if (line[i] == ' ') {
            int spaceCount = 0;
            int j = i;
            while (j < line.length() && line[j] == ' ') {
                spaceCount++;
                j++;
            }
            if (spaceCount > 0) {
                if (spaceCount % 2 == 0) { // Четное количество пробелов
                    result += 'Ч';
                }
                else { // Нечетное количество пробелов
                    result += 'Н';
                }
            }
            i = j; // Перемещаем i за последовательность пробелов
        }
        else {
            result += line[i];
            i++;
        }
    }
    return result;
}

int main() {
    std::cout << "Лабораторная работа 5: Обработка строки из файла" << std::endl;

    std::string filename = "input.txt";
    std::ifstream inputFile(filename); // Открываем файл для чтения

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return 1; // Возвращаем код ошибки
    }

    std::string line;
    // Считываем строку текста из файла
    // getline считывает до символа новой строки
    if (std::getline(inputFile, line)) {
        std::cout << "Исходная строка из файла:" << std::endl;
        std::cout << "\"" << line << "\"" << std::endl;

        std::string processedLine = processStringWithSpaces(line);

        std::cout << "\nОбработанная строка:" << std::endl;
        std::cout << "\"" << processedLine << "\"" << std::endl;
    }
    else {
        std::cout << "Файл " << filename << " пуст или не удалось прочитать строку." << std::endl;
    }

    inputFile.close(); // Закрываем файл

    // Дополнительные тесты для функции processStringWithSpaces
    std::cout << "\n--- Дополнительные тесты ---" << std::endl;
    std::string test1 = "  два пробела"; // Ч
    std::cout << "\"" << test1 << "\" -> \"" << processStringWithSpaces(test1) << "\"" << std::endl;
    std::string test2 = "   три пробела"; // Н
    std::cout << "\"" << test2 << "\" -> \"" << processStringWithSpaces(test2) << "\"" << std::endl;
    std::string test3 = "один пробел "; // Н
    std::cout << "\"" << test3 << "\" -> \"" << processStringWithSpaces(test3) << "\"" << std::endl;
    std::string test4 = "слово1  слово2   слово3    слово4"; // слово1Чслово2Нслово3Чслово4
    std::cout << "\"" << test4 << "\" -> \"" << processStringWithSpaces(test4) << "\"" << std::endl;
    std::string test5 = "    "; // Ч
    std::cout << "\"" << test5 << "\" -> \"" << processStringWithSpaces(test5) << "\"" << std::endl;
    std::string test6 = "     "; // Н
    std::cout << "\"" << test6 << "\" -> \"" << processStringWithSpaces(test6) << "\"" << std::endl;
    std::string test7 = "БезПробелов"; // БезПробелов
    std::cout << "\"" << test7 << "\" -> \"" << processStringWithSpaces(test7) << "\"" << std::endl;


    return 0;
}