package org.example;

import java.util.Scanner;

public class laba3_1 {

    public static double calculateCircumference(double radius) {
        return 2 * Math.PI * radius;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите радиус круга: ");
        double radius;
        if (scanner.hasNextDouble()) {
            radius = scanner.nextDouble();
            if (radius >= 0) {
                System.out.println("Длина окружности: " + calculateCircumference(radius));
            } else {
                System.out.println("Радиус не может быть отрицательным.");
            }
        } else {
            System.out.println("Введено некорректное значение для радиуса.");
        }
        scanner.close();
    }
}