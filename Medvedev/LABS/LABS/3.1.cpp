#include <iostream>
#include <vector>
#include <limits> // Для numeric_limits

class ArrayProcessor1D {
public:
    // Статический метод для ввода одномерного массива
    static std::vector<int> inputArray() {
        int size;
        std::cout << "Введите размер массива: ";
        while (!(std::cin >> size) || size <= 0) {
            std::cout << "Некорректный ввод. Введите положительное целое число для размера: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::vector<int> arr(size);
        std::cout << "Введите " << size << " элементов массива:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "Элемент [" << i << "]: ";
            while (!(std::cin >> arr[i])) {
                std::cout << "Некорректный ввод. Введите целое число для элемента [" << i << "]: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return arr;
    }

    // Статический метод для определения количества локальных максимумов
    static int countLocalMaxima(const std::vector<int>& arr) {
        int count = 0;
        if (arr.size() < 3) {
            return 0; // Не может быть локальных максимумов в массиве менее 3 элементов
        }
        for (size_t i = 1; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                count++;
            }
        }
        return count;
    }

    // Статический метод для вывода одномерного массива и результата
    static void printArrayAndResult(const std::vector<int>& arr, int maximaCount) {
        std::cout << "Массив: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
        }
        std::cout << std::endl;
        std::cout << "Количество локальных максимумов: " << maximaCount << std::endl;
    }
};

int main() {
    system("chcp 1251");
    std::cout << "Лабораторная работа 3, Задание 2, Код 1: Локальные максимумы" << std::endl;

    std::vector<int> myArray = ArrayProcessor1D::inputArray();
    int maxima = ArrayProcessor1D::countLocalMaxima(myArray);
    ArrayProcessor1D::printArrayAndResult(myArray, maxima);

    // Пример для теста
    std::cout << "\n--- Тестовый пример ---" << std::endl;
    std::vector<int> testArray = { 1, 3, 2, 5, 4, 6, 2, 8, 7, 3 };
    // Ожидаемые максимумы: 3 (в 1,3,2), 5 (в 2,5,4), 6 (в 4,6,2), 8 (в 2,8,7)
    int testMaxima = ArrayProcessor1D::countLocalMaxima(testArray);
    ArrayProcessor1D::printArrayAndResult(testArray, testMaxima); // Ожидаем 4

    std::vector<int> shortArray = { 1, 2 };
    int shortMaxima = ArrayProcessor1D::countLocalMaxima(shortArray);
    ArrayProcessor1D::printArrayAndResult(shortArray, shortMaxima); // Ожидаем 0

    return 0;
}