using System;

public class LocalMaxima
{
    public static int CountLocalMaxima(int[] arr)
    {
        if (arr == null || arr.Length < 3)
        {
            return 0; // Невозможно найти локальный максимум в массиве меньше чем из 3 элементов
        }

        int count = 0;
        for (int i = 1; i < arr.Length - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                count++;
            }
        }
        return count;
    }

    public static void Main(string[] args)
    {
        int[] arr = { 1, 2, 3, 2, 4, 1, 5, 3 };
        int localMaximaCount = CountLocalMaxima(arr);
        Console.WriteLine($"Количество локальных максимумов: {localMaximaCount}"); 

        int[] arr2 = { 1, 2, 1, 3, 4, 5, 4, 2 };
        localMaximaCount = CountLocalMaxima(arr2);
        Console.WriteLine($"Количество локальных максимумов: {localMaximaCount}"); 

        int[] arr3 = { 1, 2, 3, 4, 5 };
        localMaximaCount = CountLocalMaxima(arr3);
        Console.WriteLine($"Количество локальных максимумов: {localMaximaCount}");

        int[] arr4 = { 5, 4, 3, 2, 1 };
        localMaximaCount = CountLocalMaxima(arr4);
        Console.WriteLine($"Количество локальных максимумов: {localMaximaCount}"); 

        int[] arr5 = { 1, 5, 1, 5, 1 };
        localMaximaCount = CountLocalMaxima(arr5);
        Console.WriteLine($"Количество локальных максимумов: {localMaximaCount}"); 
    }
}