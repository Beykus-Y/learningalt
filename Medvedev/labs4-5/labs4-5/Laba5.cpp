#include <iostream>
#include <string>
#include <fstream>
#include <codecvt>
#include <locale>
#include <windows.h>

namespace org_example {

    std::wstring processStringWithSpaces(const std::wstring& input) {
        if (input.empty()) {
            return L"";
        }

        std::wstring result_str;
        result_str.reserve(input.length());
        int spaceCount = 0;

        const wchar_t CH_REPLACEMENT = L'Ч';
        const wchar_t N_REPLACEMENT = L'Н';

        for (wchar_t currentChar : input) {
            if (currentChar == L' ') {
                spaceCount++;
            }
            else {
                if (spaceCount > 0) {
                    result_str += (spaceCount % 2 == 0) ? CH_REPLACEMENT : N_REPLACEMENT;
                    spaceCount = 0;
                }
                result_str += currentChar;
            }
        }

        if (spaceCount > 0) {
            result_str += (spaceCount % 2 == 0) ? CH_REPLACEMENT : N_REPLACEMENT;
        }

        return result_str;
    }

} // namespace org_example

int main() {
    // Настройка консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::locale::global(std::locale(""));

    std::wifstream inputFile("C:/test/input.txt");
    inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8<wchar_t>));

    if (!inputFile) {
        std::wcerr << L"Не удалось открыть файл C:/test/input.txt" << std::endl;
        return 1;
    }

    std::wstring content((std::istreambuf_iterator<wchar_t>(inputFile)), std::istreambuf_iterator<wchar_t>());
    inputFile.close();

    std::wcout << L"Исходная строка: " << content << std::endl;

    std::wstring processedContent = org_example::processStringWithSpaces(content);
    std::wcout << L"Обработанная строка: " << processedContent << std::endl;

    return 0;
}
