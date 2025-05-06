#include <iostream>
#include <string>


namespace org_example {

    std::string processStringWithSpaces(const std::string& input) {
        if (input.empty()) {
            return "";
        }

        std::string result_str;
        result_str.reserve(input.length()); // Оптимизация
        int spaceCount = 0;

        const std::string CH_REPLACEMENT = "Ч";
        const std::string N_REPLACEMENT = "Н";

        for (char currentChar : input) {
            if (currentChar == ' ') {
                spaceCount++;
            }
            else {
                if (spaceCount > 0) {
                    if (spaceCount % 2 == 0) {
                        result_str += CH_REPLACEMENT;
                    }
                    else {
                        result_str += N_REPLACEMENT;
                    }
                    spaceCount = 0;
                }
                result_str += currentChar;
            }
        }
        // Обработка пробелов в конце строки
        if (spaceCount > 0) {
            if (spaceCount % 2 == 0) {
                result_str += CH_REPLACEMENT;
            }
            else {
                result_str += N_REPLACEMENT;
            }
        }
        return result_str;
    }

} // namespace org_example

int main() {
    system("chcp 1251");
    std::string content;
    std::cout << "Введите строку текста:" << std::endl;
    std::getline(std::cin, content); // Чтение всей строки, включая пробелы

    std::cout << "Исходная строка: " << content << std::endl;

    std::string processedContent = org_example::processStringWithSpaces(content);
    std::cout << "Обработанная строка: " << processedContent << std::endl;

    return 0;
}