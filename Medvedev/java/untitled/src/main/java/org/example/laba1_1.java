package org.example;

import java.util.Scanner;

public class laba1_1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите три положительных вещественных числа a, b, c:");

        System.out.print("a: ");
        double a = scanner.nextDouble();

        System.out.print("b: ");
        double b = scanner.nextDouble();

        System.out.print("c: ");
        double c = scanner.nextDouble();

        if (isTriangle(a, b, c)) {
            System.out.println("Треугольник существует.");

            if (isIsosceles(a, b, c)) {
                System.out.println("Треугольник является равнобедренным.");
            } else {
                System.out.println("Треугольник не является равнобедренным.");
            }
        } else {
            System.out.println("Треугольник не существует.");
        }

        scanner.close();
    }

    // Функция для проверки существования треугольника
    public static boolean isTriangle(double a, double b, double c) {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    // Функция для проверки, является ли треугольник равнобедренным
    public static boolean isIsosceles(double a, double b, double c) {
        return (a == b) || (a == c) || (b == c);
    }
}