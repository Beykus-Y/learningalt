#include <iostream>
#include <cmath> // Для std::abs

class Rectangle {
private:
    int x1, y1; // Координаты левого верхнего угла
    int x2, y2; // Координаты правого нижнего угла

public:
    // Конструктор для инициализации полей
    Rectangle(int X1, int Y1, int X2, int Y2) {
        // Для простоты предполагаем, что (x1, y1) - это левый верхний, 
        // а (x2, y2) - правый нижний.
        // Можно добавить проверку и поменять их местами, если это не так.
        if (X1 > X2) std::swap(X1, X2);
        if (Y1 > Y2) std::swap(Y1, Y2); // Обычно Y-координаты растут вниз на экране,
        // но для геометрии удобнее Y1 < Y2 для верхнего.
        // Если y1 - верхний, y2 - нижний, то y1 < y2 при стандартной ориентации осей.
        // Если экранные координаты (y растет вниз), то y1 (верхний) < y2 (нижний).
        // Будем считать, что X1<X2, Y1<Y2 - корректный прямоугольник

        x1 = X1;
        y1 = Y1;
        x2 = X2;
        y2 = Y2;
    }

    // Метод 1: Определить, является ли прямоугольник квадратом
    bool isSquare() const {
        if (x1 == x2 || y1 == y2) return false; // Это линия или точка, не квадрат
        int width = std::abs(x2 - x1);
        int height = std::abs(y2 - y1);
        return width == height;
    }

    // Метод 2: Вычислить площадь прямоугольника в пикселях
    int calculateArea() const {
        if (x1 == x2 || y1 == y2) return 0; // Площадь линии или точки равна 0
        int width = std::abs(x2 - x1);
        int height = std::abs(y2 - y1);
        return width * height;
    }

    // Вспомогательный метод для вывода информации
    void printInfo() const {
        std::cout << "Прямоугольник с координатами: (" << x1 << "," << y1 << ") - (" << x2 << "," << y2 << ")" << std::endl;
        std::cout << "  Ширина: " << std::abs(x2 - x1) << ", Высота: " << std::abs(y2 - y1) << std::endl;
        std::cout << "  Является квадратом? " << (isSquare() ? "Да" : "Нет") << std::endl;
        std::cout << "  Площадь: " << calculateArea() << " пикселей" << std::endl;
    }
};

int main() {
    system("chcp 1251");
    std::cout << "Лабораторная работа 4: Класс Прямоугольник" << std::endl;

    // Пример 1: Квадрат
    Rectangle rect1(10, 10, 60, 60); // x1, y1, x2, y2 (ширина 50, высота 50)
    rect1.printInfo();
    std::cout << std::endl;

    // Пример 2: Прямоугольник
    Rectangle rect2(100, 50, 250, 150); // ширина 150, высота 100
    rect2.printInfo();
    std::cout << std::endl;

    // Пример 3: Прямоугольник с перепутанными координатами (конструктор должен исправить)
    Rectangle rect3(80, 120, 30, 20); // (x2 < x1, y2 < y1) -> (30,20) - (80,120)
    rect3.printInfo();               // ширина 50, высота 100
    std::cout << std::endl;

    // Пример 4: Линия (не квадрат, площадь 0)
    Rectangle rect4(5, 5, 5, 20);
    rect4.printInfo();
    std::cout << std::endl;

    Rectangle rect5(5, 5, 20, 5);
    rect5.printInfo();
    std::cout << std::endl;

    // Пример 5: Точка (не квадрат, площадь 0)
    Rectangle rect6(7, 7, 7, 7);
    rect6.printInfo();
    std::cout << std::endl;

    return 0;
}