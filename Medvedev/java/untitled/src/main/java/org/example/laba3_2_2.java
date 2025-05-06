package org.example;

import java.util.Scanner;

public class laba3_2_2 {

    public static int[][] inputMatrix(Scanner scanner) {
        int M, N;
        while (true) {
            System.out.print("Введите количество строк M (четное число): ");
            if (scanner.hasNextInt()) {
                M = scanner.nextInt();
                if (M > 0 && M % 2 == 0) {
                    break;
                } else {
                    System.out.println("M должно быть положительным четным числом.");
                }
            } else {
                System.out.println("Некорректный ввод. Введите число.");
                scanner.next(); // очистка буфера
            }
        }

        while (true) {
            System.out.print("Введите количество столбцов N (четное число): ");
            if (scanner.hasNextInt()) {
                N = scanner.nextInt();
                if (N > 0 && N % 2 == 0) {
                    break;
                } else {
                    System.out.println("N должно быть положительным четным числом.");
                }
            } else {
                System.out.println("Некорректный ввод. Введите число.");
                scanner.next(); // очистка буфера
            }
        }

        int[][] matrix = new int[M][N];
        System.out.println("Введите элементы матрицы:");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print("Элемент [" + i + "][" + j + "]: ");
                if (scanner.hasNextInt()) {
                    matrix[i][j] = scanner.nextInt();
                } else {
                    System.out.println("Некорректный ввод. Установлено значение 0.");
                    matrix[i][j] = 0;
                    scanner.next(); // очистка буфера
                }
            }
        }
        return matrix;
    }

    public static void processMatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            System.out.println("Матрица пуста или не инициализирована.");
            return;
        }
        int M = matrix.length;
        int N = matrix[0].length;

        if (M % 2 != 0 || N % 2 != 0) {
            // Эта проверка теперь менее вероятна из-за валидации в inputMatrix,
            // но оставим для полноты.
            System.out.println("Матрица должна иметь четные размеры (M и N).");
            return;
        }

        int halfM = M / 2;
        int halfN = N / 2;

        for (int i = 0; i < halfM; i++) {
            for (int j = 0; j < halfN; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i + halfM][j + halfN];
                matrix[i + halfM][j + halfN] = temp;
            }
        }
    }

    public static void outputMatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        for (int[] row : matrix) {
            for (int elem : row) {
                System.out.print(elem + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] matrix = inputMatrix(scanner);

        System.out.println("Исходная матрица:");
        outputMatrix(matrix);

        processMatrix(matrix);

        System.out.println("\nМатрица после обмена четвертей:");
        outputMatrix(matrix);
        scanner.close();
    }
}