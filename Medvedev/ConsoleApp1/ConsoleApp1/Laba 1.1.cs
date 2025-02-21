using System;

public class Triangle
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Введите три положительных вещественных числа a, b, c:");

        Console.Write("a: ");
        double a = Convert.ToDouble(Console.ReadLine());

        Console.Write("b: ");
        double b = Convert.ToDouble(Console.ReadLine());

        Console.Write("c: ");
        double c = Convert.ToDouble(Console.ReadLine());

        if (IsTriangle(a, b, c))
        {
            Console.WriteLine("Треугольник существует.");

            if (IsIsosceles(a, b, c))
            {
                Console.WriteLine("Треугольник является равнобедренным.");
            }
            else
            {
                Console.WriteLine("Треугольник не является равнобедренным.");
            }
        }
        else
        {
            Console.WriteLine("Треугольник не существует.");
        }
    }

    // Функция для проверки существования треугольника
    public static bool IsTriangle(double a, double b, double c)
    {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Функция для проверки, является ли треугольник равнобедренным
    public static bool IsIsosceles(double a, double b, double c)
    {
        return (a == b) || (a == c) || (b == c);
    }
}