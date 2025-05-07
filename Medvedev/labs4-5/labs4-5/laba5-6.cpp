#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>

namespace org_example {

    class Laba5_Rectangle {
    public:
        int x1, y1, x2, y2;

        Laba5_Rectangle(int x1_val = 0, int y1_val = 0, int x2_val = 0, int y2_val = 0)
            : x1(x1_val), y1(y1_val), x2(x2_val), y2(y2_val) {
        }

        bool isSquare() const {
            int sideA = std::abs(x2 - x1);
            int sideB = std::abs(y2 - y1);
            return sideA > 0 && sideA == sideB;
        }

        int calculateArea() const {
            return std::abs(x2 - x1) * std::abs(y2 - y1);
        }

        void diskOut(std::ostream& os) const {
            if (!os.good()) throw std::runtime_error("Stream not writable");
            os << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        }

        void diskIn(std::istream& is) {
            if (!(is >> x1 >> y1 >> x2 >> y2))
                throw std::runtime_error("Failed to read rectangle from stream");
        }
    };

} // namespace org_example

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        int N;
        std::cout << "Сколько прямоугольников создать? ";
        std::cin >> N;
        if (N <= 0) throw std::invalid_argument("N должно быть положительным");

        std::vector<org_example::Laba5_Rectangle> rects;
        rects.reserve(N);

        for (int i = 0; i < N; ++i) {
            int x1, y1, x2, y2;
            std::cout << "Прямоугольник " << (i + 1) << ":\n";
            std::cout << "  x1: "; std::cin >> x1;
            std::cout << "  y1: "; std::cin >> y1;
            std::cout << "  x2: "; std::cin >> x2;
            std::cout << "  y2: "; std::cin >> y2;
            rects.emplace_back(x1, y1, x2, y2);
        }

        // Запись в файл
        std::ofstream ofs("rectangles.txt");
        if (!ofs) throw std::ios_base::failure("Не удалось открыть файл для записи");
        for (const auto& r : rects) r.diskOut(ofs);
        ofs.close();

        // Чтение из файла
        std::ifstream ifs("rectangles.txt");
        if (!ifs) throw std::ios_base::failure("Не удалось открыть файл для чтения");
        std::vector<org_example::Laba5_Rectangle> loaded;
        loaded.reserve(N);
        for (int i = 0; i < N; ++i) {
            org_example::Laba5_Rectangle r;
            r.diskIn(ifs);
            loaded.push_back(r);
        }

        // Вывод загруженных
        std::cout << "\nЗагруженные прямоугольники:\n";
        for (size_t i = 0; i < loaded.size(); ++i) {
            const auto& r = loaded[i];
            std::cout << "Прямоугольник " << (i + 1) << ": ("
                << r.x1 << "," << r.y1 << ") - ("
                << r.x2 << "," << r.y2 << "), "
                << "Кв? " << std::boolalpha << r.isSquare()
                << ", Пл. " << r.calculateArea() << "\n";
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
