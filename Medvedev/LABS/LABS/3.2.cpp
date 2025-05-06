#include <iostream>
#include <vector>
#include <limits> // ��� numeric_limits
#include <algorithm> // ��� std::swap

class MatrixProcessor2D {
public:
    // ����������� ����� ��� ����� ���������� ������� (�������)
    static std::vector<std::vector<int>> inputMatrix() {
        int rows, cols;
        std::cout << "������� ���������� ����� M (������ �����): ";
        while (!(std::cin >> rows) || rows <= 0 || rows % 2 != 0) {
            std::cout << "������������ ����. M ������ ���� ������������� ������ ������: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "������� ���������� �������� N (������ �����): ";
        while (!(std::cin >> cols) || cols <= 0 || cols % 2 != 0) {
            std::cout << "������������ ����. N ������ ���� ������������� ������ ������: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
        std::cout << "������� �������� ������� (" << rows << "x" << cols << "):" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "������� [" << i << "][" << j << "]: ";
                while (!(std::cin >> matrix[i][j])) {
                    std::cout << "������������ ����. ������� ����� ����� ��� �������� [" << i << "][" << j << "]: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        return matrix;
    }

    // ����������� ����� ��� ������ ��������� �������
    // ������� ���������� �� ������, ��� ��� ��� ����� ����������
    static void swapQuarters(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            std::cout << "������� �����." << std::endl;
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows % 2 != 0 || cols % 2 != 0) {
            std::cout << "������: ������� ������� ������ ���� ������� ��� ������ ���������." << std::endl;
            return;
        }

        int halfRows = rows / 2;
        int halfCols = cols / 2;

        for (int i = 0; i < halfRows; ++i) {
            for (int j = 0; j < halfCols; ++j) {
                // ����� �������� �� ����� ������� �������� (matrix[i][j])
                // � ��������� �� ������ ������ �������� (matrix[i + halfRows][j + halfCols])
                std::swap(matrix[i][j], matrix[i + halfRows][j + halfCols]);
            }
        }
    }

    // ����������� ����� ��� ������ �������
    static void printMatrix(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            std::cout << "������� �����." << std::endl;
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
    std::cout << "������������ ������ 3, ������� 2, ��� 2: ����� ��������� �������" << std::endl;

    std::vector<std::vector<int>> myMatrix = MatrixProcessor2D::inputMatrix();

    std::cout << "\n�������� �������:" << std::endl;
    MatrixProcessor2D::printMatrix(myMatrix);

    MatrixProcessor2D::swapQuarters(myMatrix);

    std::cout << "\n������� ����� ������ ���������:" << std::endl;
    MatrixProcessor2D::printMatrix(myMatrix);

    std::cout << "\n--- �������� ������ 4x4 ---" << std::endl;
    std::vector<std::vector<int>> testMatrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::cout << "�������� �������:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix);
    MatrixProcessor2D::swapQuarters(testMatrix);
    std::cout << "������� ����� ������:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix);
    /* ��������� ���������:
       11  12   3   4
       15  16   7   8
        9  10   1   2
       13  14   5   6
    */

    std::cout << "\n--- �������� ������ 2x2 ---" << std::endl;
    std::vector<std::vector<int>> testMatrix2 = {
        {1, 2},
        {3, 4}
    };
    std::cout << "�������� �������:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix2);
    MatrixProcessor2D::swapQuarters(testMatrix2);
    std::cout << "������� ����� ������:" << std::endl;
    MatrixProcessor2D::printMatrix(testMatrix2);
    /* ��������� ���������:
      4  2
      3  1
   */
    return 0;
}