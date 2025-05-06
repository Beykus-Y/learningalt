#include <iostream>
#include <vector>
#include <limits> // ��� numeric_limits

class ArrayProcessor1D {
public:
    // ����������� ����� ��� ����� ����������� �������
    static std::vector<int> inputArray() {
        int size;
        std::cout << "������� ������ �������: ";
        while (!(std::cin >> size) || size <= 0) {
            std::cout << "������������ ����. ������� ������������� ����� ����� ��� �������: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::vector<int> arr(size);
        std::cout << "������� " << size << " ��������� �������:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "������� [" << i << "]: ";
            while (!(std::cin >> arr[i])) {
                std::cout << "������������ ����. ������� ����� ����� ��� �������� [" << i << "]: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return arr;
    }

    // ����������� ����� ��� ����������� ���������� ��������� ����������
    static int countLocalMaxima(const std::vector<int>& arr) {
        int count = 0;
        if (arr.size() < 3) {
            return 0; // �� ����� ���� ��������� ���������� � ������� ����� 3 ���������
        }
        for (size_t i = 1; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                count++;
            }
        }
        return count;
    }

    // ����������� ����� ��� ������ ����������� ������� � ����������
    static void printArrayAndResult(const std::vector<int>& arr, int maximaCount) {
        std::cout << "������: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
        }
        std::cout << std::endl;
        std::cout << "���������� ��������� ����������: " << maximaCount << std::endl;
    }
};

int main() {
    system("chcp 1251");
    std::cout << "������������ ������ 3, ������� 2, ��� 1: ��������� ���������" << std::endl;

    std::vector<int> myArray = ArrayProcessor1D::inputArray();
    int maxima = ArrayProcessor1D::countLocalMaxima(myArray);
    ArrayProcessor1D::printArrayAndResult(myArray, maxima);

    // ������ ��� �����
    std::cout << "\n--- �������� ������ ---" << std::endl;
    std::vector<int> testArray = { 1, 3, 2, 5, 4, 6, 2, 8, 7, 3 };
    // ��������� ���������: 3 (� 1,3,2), 5 (� 2,5,4), 6 (� 4,6,2), 8 (� 2,8,7)
    int testMaxima = ArrayProcessor1D::countLocalMaxima(testArray);
    ArrayProcessor1D::printArrayAndResult(testArray, testMaxima); // ������� 4

    std::vector<int> shortArray = { 1, 2 };
    int shortMaxima = ArrayProcessor1D::countLocalMaxima(shortArray);
    ArrayProcessor1D::printArrayAndResult(shortArray, shortMaxima); // ������� 0

    return 0;
}