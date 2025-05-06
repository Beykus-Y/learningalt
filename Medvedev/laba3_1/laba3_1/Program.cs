using System;

namespace org.example
{
    public class Laba3_1
    {
        public static double CalculateCircumference(double radius)
        {
            return 2 * Math.PI * radius;
        }

        public static void Main(string[] args)
        {
            Console.Write("Введите радиус круга: ");
            string inputRadius = Console.ReadLine();
            double radius;

            if (double.TryParse(inputRadius, out radius))
            {
                if (radius >= 0)
                {
                    Console.WriteLine("Длина окружности: " + CalculateCircumference(radius));
                }
                else
                {
                    Console.WriteLine("Радиус не может быть отрицательным.");
                }
            }
            else
            {
                Console.WriteLine("Введено некорректное значение для радиуса.");
            }
        }
    }
}