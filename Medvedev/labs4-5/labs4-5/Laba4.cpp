
#include <iostream>
#include <cmath> 
#include <string>

namespace org_example {

    class Laba4_Rectangle {
    public:
        int x1, y1, x2, y2;

        Laba4_Rectangle(int x1_val, int y1_val, int x2_val, int y2_val) :
            x1(x1_val), y1(y1_val), x2(x2_val), y2(y2_val) {
        }

        bool isSquare() const {
            int sideA = std::abs(this->x2 - this->x1);
            int sideB = std::abs(this->y2 - this->y1);
            return sideA > 0 && sideA == sideB;
        }

        int calculateArea() const {
            int sideA = std::abs(this->x2 - this->x1);
            int sideB = std::abs(this->y2 - this->y1);
            return sideA * sideB;
        }
    };

} // namespace org_example

int main() {
    int x1_in, y1_in, x2_in, y2_in;

    std::cout << "Введите координаты левого верхнего угла (x1, y1):" << std::endl;
    std::cout << "x1: ";
    std::cin >> x1_in;
    std::cout << "y1: ";
    std::cin >> y1_in;

    std::cout << "Введите координаты правого нижнего угла (x2, y2):" << std::endl;
    std::cout << "x2: ";
    std::cin >> x2_in;
    std::cout << "y2: ";
    std::cin >> y2_in;

    org_example::Laba4_Rectangle rect(x1_in, y1_in, x2_in, y2_in);

    std::cout << "\nИнформация о прямоугольнике:" << std::endl;
    std::cout << "  Координаты: (" << rect.x1 << "," << rect.y1 << ") - (" << rect.x2 << "," << rect.y2 << ")" << std::endl;
    std::cout << "  Квадрат? " << std::boolalpha << rect.isSquare() << std::endl;
    std::cout << "  Площадь: " << rect.calculateArea() << std::endl;

    return 0;
}