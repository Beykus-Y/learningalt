package org.example;

import java.util.Scanner;

public class Laba4_Rectangle {
    int x1, y1, x2, y2;

    public Laba4_Rectangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public boolean isSquare() {
        int sideA = Math.abs(this.x2 - this.x1);
        int sideB = Math.abs(this.y2 - this.y1);
        return sideA > 0 && sideA == sideB;
    }

    public int calculateArea() {
        int sideA = Math.abs(this.x2 - this.x1);
        int sideB = Math.abs(this.y2 - this.y1);
        return sideA * sideB;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите координаты левого верхнего угла (x1, y1):");
        System.out.print("x1: ");
        int x1 = scanner.nextInt();
        System.out.print("y1: ");
        int y1 = scanner.nextInt();

        System.out.println("Введите координаты правого нижнего угла (x2, y2):");
        System.out.print("x2: ");
        int x2 = scanner.nextInt();
        System.out.print("y2: ");
        int y2 = scanner.nextInt();

        Laba4_Rectangle rect = new Laba4_Rectangle(x1, y1, x2, y2);

        System.out.println("\nИнформация о прямоугольнике:");
        System.out.println("  Координаты: (" + rect.x1 + "," + rect.y1 + ") - (" + rect.x2 + "," + rect.y2 + ")");
        System.out.println("  Квадрат? " + rect.isSquare());
        System.out.println("  Площадь: " + rect.calculateArea());

        scanner.close();
    }
}