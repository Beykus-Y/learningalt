package org.example;

import java.io.*;
import java.util.Scanner;

public class Laba5_Rectangle {
    private int x1, y1, x2, y2;

    public Laba5_Rectangle() {}

    public Laba5_Rectangle(int x1, int y1, int x2, int y2) {
        this.x1 = x1; this.y1 = y1; this.x2 = x2; this.y2 = y2;
    }

    public boolean isSquare() {
        int sideA = Math.abs(x2 - x1);
        int sideB = Math.abs(y2 - y1);
        return sideA > 0 && sideA == sideB;
    }

    public int calculateArea() {
        return Math.abs(x2 - x1) * Math.abs(y2 - y1);
    }

    public void diskOut(BufferedWriter bw) throws IOException {
        bw.write(x1 + " " + y1 + " " + x2 + " " + y2);
        bw.newLine();
    }

    public void diskIn(BufferedReader br) throws IOException {
        String line = br.readLine();
        if (line == null) throw new EOFException("Нечего читать");
        String[] parts = line.split("\\s+");
        if (parts.length != 4) throw new IOException("Неверный формат данных");
        x1 = Integer.parseInt(parts[0]);
        y1 = Integer.parseInt(parts[1]);
        x2 = Integer.parseInt(parts[2]);
        y2 = Integer.parseInt(parts[3]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            System.out.print("Сколько прямоугольников? ");
            int N = sc.nextInt();
            if (N <= 0) throw new IllegalArgumentException("N должно быть > 0");

            Laba5_Rectangle[] arr = new Laba5_Rectangle[N];
            for (int i = 0; i < N; i++) {
                System.out.println("Прямоугольник " + (i+1) + ":");
                System.out.print("  x1: "); int x1 = sc.nextInt();
                System.out.print("  y1: "); int y1 = sc.nextInt();
                System.out.print("  x2: "); int x2 = sc.nextInt();
                System.out.print("  y2: "); int y2 = sc.nextInt();
                arr[i] = new Laba5_Rectangle(x1, y1, x2, y2);
            }

            // Запись
            try (BufferedWriter bw = new BufferedWriter(new FileWriter("rectangles.txt"))) {
                for (Laba5_Rectangle r : arr) r.diskOut(bw);
            }

            // Чтение
            Laba5_Rectangle[] loaded = new Laba5_Rectangle[N];
            try (BufferedReader br = new BufferedReader(new FileReader("rectangles.txt"))) {
                for (int i = 0; i < N; i++) {
                    Laba5_Rectangle r = new Laba5_Rectangle();
                    r.diskIn(br);
                    loaded[i] = r;
                }
            }

            // Вывод
            System.out.println("\nЗагруженные:");
            for (int i = 0; i < loaded.length; i++) {
                Laba5_Rectangle r = loaded[i];
                System.out.printf(" %d: (%d,%d)-(%d,%d), Кв? %b, Пл. %d%n",
                        i+1, r.x1, r.y1, r.x2, r.y2,
                        r.isSquare(), r.calculateArea());
            }
        }
        catch (Exception ex) {
            System.err.println("Ошибка: " + ex.getMessage());
        }
        finally {
            sc.close();
        }
    }
}
