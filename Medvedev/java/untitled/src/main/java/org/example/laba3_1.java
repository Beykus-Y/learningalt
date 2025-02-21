package org.example;

import java.util.Scanner;

public class laba3_1 {

    public static double calculateCircumference(double radius) {
        return 2 * Math.PI * radius;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("radius: ");
        double radius = scanner.nextDouble();
        double circumference = calculateCircumference(radius);
        System.out.println("Длина окружности с радиусом " + radius + " равна " + circumference);

        radius = 10.0;
        circumference = calculateCircumference(radius);
        System.out.println("Длина окружности с радиусом " + radius + " равна " + circumference);
    }
}