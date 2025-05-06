package org.example;

import java.util.Arrays;
import java.util.Scanner;

public class laba3_2_1 {

    public static int[] inputArray(Scanner scanner) {
        System.out.print("Введите количество элементов массива: ");
        int n;
        if (scanner.hasNextInt()) {
            n = scanner.nextInt();
            if (n <= 0) {
                System.out.println("Размер массива должен быть положительным.");
                return new int[0]; // Возвращаем пустой массив в случае некорректного размера
            }
        } else {
            System.out.println("Некорректный ввод для количества элементов.");
            scanner.next(); // Очистка некорректного ввода
            return new int[0];
        }

        int[] arr = new int[n];
        System.out.println("Введите элементы массива:");
        for (int i = 0; i < n; i++) {
            System.out.print("Элемент " + (i + 1) + ": ");
            if (scanner.hasNextInt()) {
                arr[i] = scanner.nextInt();
            } else {
                System.out.println("Некорректный ввод элемента. Установлено значение 0.");
                arr[i] = 0;
                scanner.next(); // Очистка некорректного ввода
            }
        }
        return arr;
    }

    public static int processArray(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0;
        }
        int count = 0;
        for (int i = 1; i < arr.length - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                count++;
            }
        }
        return count;
    }

    public static void outputArray(int[] arr, int result) {
        if (arr == null || arr.length == 0) {
            System.out.println("Массив не был корректно инициализирован.");
            return;
        }
        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Количество локальных максимумов: " + result);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = inputArray(scanner);
        if (arr.length > 0) { // Обрабатываем только если массив был создан
            int localMaximaCount = processArray(arr);
            outputArray(arr, localMaximaCount);
        }
        scanner.close();
    }
}