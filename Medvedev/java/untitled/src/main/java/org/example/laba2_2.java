package org.example;

public class laba2_2 {

    public static void swapMatrixQuarters(int[][] matrix) {
        int M = matrix.length;
        int N = matrix[0].length;

        if (M % 2 != 0 || N % 2 != 0) {
            System.out.println("Матрица должна иметь четные размеры (M и N).");
            return;
        }

        int halfM = M / 2;
        int halfN = N / 2;

        // Обмен элементов левой верхней и правой нижней четвертей поэлементно
        for (int i = 0; i < halfM; i++) {
            for (int j = 0; j < halfN; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i + halfM][j + halfN];
                matrix[i + halfM][j + halfN] = temp;
            }
        }
    }

    public static void printMatrix(int[][] matrix) {
        int M = matrix.length;
        int N = matrix[0].length;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}
        };

        System.out.println("Исходная матрица:");
        printMatrix(matrix);

        swapMatrixQuarters(matrix);

        System.out.println("\nМатрица после обмена четвертей:");
        printMatrix(matrix);
    }
}
