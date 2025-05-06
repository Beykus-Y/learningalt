#include <iostream>
#include <cmath> // ��� std::abs

class Rectangle {
private:
    int x1, y1; // ���������� ������ �������� ����
    int x2, y2; // ���������� ������� ������� ����

public:
    // ����������� ��� ������������� �����
    Rectangle(int X1, int Y1, int X2, int Y2) {
        // ��� �������� ������������, ��� (x1, y1) - ��� ����� �������, 
        // � (x2, y2) - ������ ������.
        // ����� �������� �������� � �������� �� �������, ���� ��� �� ���.
        if (X1 > X2) std::swap(X1, X2);
        if (Y1 > Y2) std::swap(Y1, Y2); // ������ Y-���������� ������ ���� �� ������,
        // �� ��� ��������� ������� Y1 < Y2 ��� ��������.
        // ���� y1 - �������, y2 - ������, �� y1 < y2 ��� ����������� ���������� ����.
        // ���� �������� ���������� (y ������ ����), �� y1 (�������) < y2 (������).
        // ����� �������, ��� X1<X2, Y1<Y2 - ���������� �������������

        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
    }

    // ����� 1: ����������, �������� �� ������������� ���������
    bool isSquare() const {
        if (x1 == x2 || y1 == y2) return false; // ��� ����� ��� �����, �� �������
        int width = std::abs(x2 - x1);
        int height = std::abs(y2 - y1);
        return width == height;
    }

    // ����� 2: ��������� ������� �������������� � ��������
    int calculateArea() const {
        if (x1 == x2 || y1 == y2) return 0; // ������� ����� ��� ����� ����� 0
        int width = std::abs(x2 - x1);
        int height = std::abs(y2 - y1);
        return width * height;
    }

    // ��������������� ����� ��� ������ ����������
    void printInfo() const {
        std::cout << "������������� � ������������: (" << x1 << "," << y1 << ") - (" << x2 << "," << y2 << ")" << std::endl;
        std::cout << "  ������: " << std::abs(x2 - x1) << ", ������: " << std::abs(y2 - y1) << std::endl;
        std::cout << "  �������� ���������? " << (isSquare() ? "��" : "���") << std::endl;
        std::cout << "  �������: " << calculateArea() << " ��������" << std::endl;
    }
};

int main() {
    system("chcp 1251");
    std::cout << "������������ ������ 4: ����� �������������" << std::endl;

    // ������ 1: �������
    Rectangle rect1(10, 10, 60, 60); // x1, y1, x2, y2 (������ 50, ������ 50)
    rect1.printInfo();
    std::cout << std::endl;

    // ������ 2: �������������
    Rectangle rect2(100, 50, 250, 150); // ������ 150, ������ 100
    rect2.printInfo();
    std::cout << std::endl;

    // ������ 3: ������������� � ������������� ������������ (����������� ������ ���������)
    Rectangle rect3(80, 120, 30, 20); // (x2 < x1, y2 < y1) -> (30,20) - (80,120)
    rect3.printInfo();               // ������ 50, ������ 100
    std::cout << std::endl;

    // ������ 4: ����� (�� �������, ������� 0)
    Rectangle rect4(5, 5, 5, 20);
    rect4.printInfo();
    std::cout << std::endl;

    Rectangle rect5(5, 5, 20, 5);
    rect5.printInfo();
    std::cout << std::endl;

    // ������ 5: ����� (�� �������, ������� 0)
    Rectangle rect6(7, 7, 7, 7);
    rect6.printInfo();
    std::cout << std::endl;

    return 0;
}