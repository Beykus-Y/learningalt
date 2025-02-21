using System;

public class Circle
{
    public static double CalculateCircumference(double radius)
    {
        return 2 * Math.PI * radius;
    }

    public static void Main(string[] args)
    {

        Console.Write("Введите радиус: ");
        double radius = Convert.ToDouble(Console.ReadLine());
        double circumference = CalculateCircumference(radius);
        Console.WriteLine($"Длина окружности с радиусом {radius} равна {circumference}");

        radius = 10.0;
        circumference = CalculateCircumference(radius);
        Console.WriteLine($"Длина окружности с радиусом {radius} равна {circumference}");
    }
}