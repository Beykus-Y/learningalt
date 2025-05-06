#include <iostream>
#include <vector>
#include <limits> // Для numeric_limits
#include <algorithm> // Для std::swap

class MatrixProcessor2D {
public:
    // Статический метод для ввода двумерного массива (матрицы)
    static std::vector<std::vector<int>> inputMatrix() {
        int rows, cols;
        std::cout << "Введите количество строк M (четное число): ";
        while (!(std::cin >> rows) || rows <= 0 || rows % 2 != 0) {
            std::cout << "Некорректный ввод. M должно быть положительным четным числом: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Введите количество столбцов N (четное число): ";
        while (!(std::cin >> cols) || cols <= 0 || cols % 2 != 0) {
            std::cout << "Некорректный ввод. N должно быть положительным четным числом: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
        std::cout << "Введите элементы матрицы (" << rows << "x" << cols << "):" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Элемент [" << i << "][" << j << "]: ";
                while (!(std::cin >> matrix[i][j])) {
                    std::cout << "Некорректный ввод. Введите целое число для элемента [" << i << "][" << j << "]: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        return matrix;
    }

    // Статический метод для обмена четвертей матрицы
    // Матрица передается по ссылке, так как она будет изменяться
    static void swapQuarters(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            std::cout << "Матрица пуста." << std::endl;
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows % 2 != 0 || cols % 2 != 0) {
            std::cout << "Ошибка: Размеры матрицы должны быть четными для обмена четвертей." << std::endl;
            return;
        }

        int halfRows = rows / 2;
        int halfCols = cols / 2;

        for (int i = 0; i < halfRows; ++i) {
            for (int j = 0; j < halfCols; ++j) {
                // Обмен элемента из левой верхней четверти (matrix[i][j])
                // с элементом из правой нижней четверти (matrix[i + halfRows][j + halfCols])
                std::swap(matrix[i][j], matrix[i + halfRows][j + halfCols]);
            }
        }
    }

    // Статический метод для вывода матрицы
    static void printMatrix(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            std::cout << "Матрица пуста." << std::endl;
            return;
        }
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    system("chcp 1251");
    std::cout << "Лабораторная работа 3, Задание 2, Код 2: Обмен четвертей матрицы" << std::endl;

    std::vector<std::vector<int>> myMatrix = MatrixProcessor2D::inputMatrix();

    std::cout << "\nИсходная матрица:" << std::endl;
    MatrixProcessor2D::printMatrix(myMatrix);

    MatrixProcessor2D::swapQuarters(myMatrix);

    std::cout << "\nМатрица после обмена четвертей:" << std::endl;
    MatrixProcessor2D::printMatrix(myMatrix);

    std::cout << "\n--- Тестовый пример 4x4 ---" << std::endl;
    std::vector<std::vector<int>> testMatrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::cout << "Исходная матрица:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix);
    MatrixProcessor2D::swapQuarters(testMatrix);
    std::cout << "Матрица после обмена:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix);
    /* Ожидаемый результат:
       11  12   3   4
       15  16   7   8
        9  10   1   2
       13  14   5   6
    */

    std::cout << "\n--- Тестовый пример 2x2 ---" << std::endl;
    std::vector<std::vector<int>> testMatrix2 = {
        {1, 2},
        {3, 4}
    };
    std::cout << "Исходная матрица:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix2);
    MatrixProcessor2D::swapQuarters(testMatrix2);
    std::cout << "Матрица после обмена:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix2);
    /* Ожидаемый результат:
      4  2
      3  1
   */
    return 0;
}