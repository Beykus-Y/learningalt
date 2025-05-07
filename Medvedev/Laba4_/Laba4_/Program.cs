
using System;

namespace org.example
{
    public class Laba4_Rectangle
    {
        public int x1, y1, x2, y2;

        public Laba4_Rectangle(int x1, int y1, int x2, int y2)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }

        public bool IsSquare()
        {
            int sideA = Math.Abs(this.x2 - this.x1);
            int sideB = Math.Abs(this.y2 - this.y1);
            return sideA > 0 && sideA == sideB;
        }

        public int CalculateArea()
        {
            int sideA = Math.Abs(this.x2 - this.x1);
            int sideB = Math.Abs(this.y2 - this.y1);
            return sideA * sideB;
        }

        public static void Main(string[] args) // Измените имя
        {
            Console.WriteLine("Введите координаты левого верхнего угла (x1, y1):");
            Console.Write("x1: ");
            int.TryParse(Console.ReadLine(), out int x1); // упрощенный TryParse для примера
            Console.Write("y1: ");
            int.TryParse(Console.ReadLine(), out int y1);

            Console.WriteLine("Введите координаты правого нижнего угла (x2, y2):");
            Console.Write("x2: ");
            int.TryParse(Console.ReadLine(), out int x2);
            Console.Write("y2: ");
            int.TryParse(Console.ReadLine(), out int y2);

            Laba4_Rectangle rect = new Laba4_Rectangle(x1, y1, x2, y2);

            Console.WriteLine("\nИнформация о прямоугольнике:");
            Console.WriteLine($"  Координаты: ({rect.x1},{rect.y1}) - ({rect.x2},{rect.y2})");
            Console.WriteLine("  Квадрат? " + rect.IsSquare());
            Console.WriteLine("  Площадь: " + rect.CalculateArea());
        }
    }
}