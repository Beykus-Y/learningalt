using System;

public class CreditCalculator
{
    public static void Main(string[] args)
    {
        Console.WriteLine("Введите размер кредита (k):");
        double k = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine("Введите годовую процентную ставку (p):");
        double p = Convert.ToDouble(Console.ReadLine()) / 100.0; // Переводим проценты в десятичную дробь

        Console.WriteLine("Введите годовую прибыль (r):");
        double r = Convert.ToDouble(Console.ReadLine());

        int years = 0;
        double debt = k;

        while (debt > 0)
        {
            years++;
            double interest = debt * p;  // Рассчитываем проценты за год
            debt += interest;           // Увеличиваем долг на сумму процентов
            debt -= r;                // Уменьшаем долг на сумму прибыли

            if (years > 1000)
            {
                Console.WriteLine("Кредит не будет погашен даже через 1000 лет. Возможно, прибыль недостаточна.");
                return;
            }

            if (debt < 0)
            {
                debt = 0; //  Чтобы не было отрицательного долга
            }

        }

        Console.WriteLine($"Кредит будет погашен через {years} лет.");
    }
}