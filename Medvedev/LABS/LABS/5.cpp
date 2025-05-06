#include <iostream>
#include <fstream> // ��� ������ � �������
#include <string>  // ��� std::string
#include <vector>  // �������������, �� ����� ���� �������

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
                if (spaceCount % 2 == 0) { // ������ ���������� ��������
                    result += '�';
                }
                else { // �������� ���������� ��������
                    result += '�';
                }
            }
            i = j; // ���������� i �� ������������������ ��������
        }
        else {
            result += line[i];
            i++;
        }
    }
    return result;
}

int main() {
    std::cout << "������������ ������ 5: ��������� ������ �� �����" << std::endl;

    std::string filename = "input.txt";
    std::ifstream inputFile(filename); // ��������� ���� ��� ������

    if (!inputFile.is_open()) {
        std::cerr << "������: �� ������� ������� ���� " << filename << std::endl;
        return 1; // ���������� ��� ������
    }

    std::string line;
    // ��������� ������ ������ �� �����
    // getline ��������� �� ������� ����� ������
    if (std::getline(inputFile, line)) {
        std::cout << "�������� ������ �� �����:" << std::endl;
        std::cout << "\"" << line << "\"" << std::endl;

        std::string processedLine = processStringWithSpaces(line);

        std::cout << "\n������������ ������:" << std::endl;
        std::cout << "\"" << processedLine << "\"" << std::endl;
    }
    else {
        std::cout << "���� " << filename << " ���� ��� �� ������� ��������� ������." << std::endl;
    }

    inputFile.close(); // ��������� ����

    // �������������� ����� ��� ������� processStringWithSpaces
    std::cout << "\n--- �������������� ����� ---" << std::endl;
    std::string test1 = "  ��� �������"; // �
    std::cout << "\"" << test1 << "\" -> \"" << processStringWithSpaces(test1) << "\"" << std::endl;
    std::string test2 = "   ��� �������"; // �
    std::cout << "\"" << test2 << "\" -> \"" << processStringWithSpaces(test2) << "\"" << std::endl;
    std::string test3 = "���� ������ "; // �
    std::cout << "\"" << test3 << "\" -> \"" << processStringWithSpaces(test3) << "\"" << std::endl;
    std::string test4 = "�����1  �����2   �����3    �����4"; // �����1������2������3������4
    std::cout << "\"" << test4 << "\" -> \"" << processStringWithSpaces(test4) << "\"" << std::endl;
    std::string test5 = "    "; // �
    std::cout << "\"" << test5 << "\" -> \"" << processStringWithSpaces(test5) << "\"" << std::endl;
    std::string test6 = "     "; // �
    std::cout << "\"" << test6 << "\" -> \"" << processStringWithSpaces(test6) << "\"" << std::endl;
    std::string test7 = "�����������"; // �����������
    std::cout << "\"" << test7 << "\" -> \"" << processStringWithSpaces(test7) << "\"" << std::endl;


    return 0;
}