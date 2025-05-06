#include <iostream>
#include <string>


namespace org_example {

    std::string processStringWithSpaces(const std::string& input) {
        if (input.empty()) {
            return "";
        }

        std::string result_str;
        result_str.reserve(input.length()); // �����������
        int spaceCount = 0;

        const std::string CH_REPLACEMENT = "�";
        const std::string N_REPLACEMENT = "�";

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
        // ��������� �������� � ����� ������
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
    std::cout << "������� ������ ������:" << std::endl;
    std::getline(std::cin, content); // ������ ���� ������, ������� �������

    std::cout << "�������� ������: " << content << std::endl;

    std::string processedContent = org_example::processStringWithSpaces(content);
    std::cout << "������������ ������: " << processedContent << std::endl;

    return 0;
}