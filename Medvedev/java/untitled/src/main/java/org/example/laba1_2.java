package org.example;

import java.util.Scanner;

public class laba1_2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите размер кредита (k):");
        double k = scanner.nextDouble();

        System.out.println("Введите годовую процентную ставку (p):");
        double p = scanner.nextDouble() / 100.0; // Переводим проценты в десятичную дробь

        System.out.println("Введите годовую прибыль (r):");
        double r = scanner.nextDouble();

        int years = 0;
        double debt = k;

        while (debt > 0) {
            years++;
            double interest = debt * p; // Рассчитываем проценты за год
            debt += interest;          // Увеличиваем долг на сумму процентов
            debt -= r;               // Уменьшаем долг на сумму прибыли

            if (years > 1000) { // Добавлена проверка на бесконечный цикл (например, если прибыль слишком мала)
                System.out.println("Кредит не будет погашен даже через 1000 лет. Возможно, прибыль недостаточна.");
                return;
            }

            if (debt < 0) {
                debt = 0; // Чтобы не было отрицательного долга
            }
        }

        System.out.println("Кредит будет погашен через " + years + " лет.");
        scanner.close();
    }
}