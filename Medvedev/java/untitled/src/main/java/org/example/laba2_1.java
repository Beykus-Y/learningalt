package org.example;

public class laba2_1 {

    public static int countLocalMaxima(int[] arr) {
        if (arr == null || arr.length < 3) {
            return 0; // Невозможно найти локальный максимум в массиве меньше чем из 3 элементов
        }

        int count = 0;
        for (int i = 1; i < arr.length - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 2, 4, 1, 5, 3};
        int localMaximaCount = countLocalMaxima(arr);
        System.out.println("Количество локальных максимумов: " + localMaximaCount); // Output: 3

        int[] arr2 = {1, 2, 1, 3, 4, 5, 4, 2};
        localMaximaCount = countLocalMaxima(arr2);
        System.out.println("Количество локальных максимумов: " + localMaximaCount); // Output: 3

        int[] arr3 = {1, 2, 3, 4, 5};
        localMaximaCount = countLocalMaxima(arr3);
        System.out.println("Количество локальных максимумов: " + localMaximaCount); // Output: 0

        int[] arr4 = {5, 4, 3, 2, 1};
        localMaximaCount = countLocalMaxima(arr4);
        System.out.println("Количество локальных максимумов: " + localMaximaCount); // Output: 0

        int[] arr5 = {1, 5, 1, 5, 1};
        localMaximaCount = countLocalMaxima(arr5);
        System.out.println("Количество локальных максимумов: " + localMaximaCount); // Output: 2
    }
}
