package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ввод натурального числа
        System.out.println("Введите натуральное число:");
        int number = scanner.nextInt();

        int count = 0;
        int sum = 0;
        int product = 1;

        // Проход по цифрам числа
        int temp = number;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            count++;
            temp /= 10;
        }

        // Вывод результатов
        System.out.println("Количество цифр: " + count);
        System.out.println("Сумма цифр: " + sum);
        System.out.println("Произведение цифр: " + product);

        scanner.close();
    }
}
