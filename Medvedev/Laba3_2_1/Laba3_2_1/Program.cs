using System;
using System.Linq;

namespace org.example
{
    public class Laba3_2_1
    {
        public static int[] InputArray()
        {
            Console.Write("Введите количество элементов массива: ");
            string inputN = Console.ReadLine();
            int n;

            if (!int.TryParse(inputN, out n) || n <= 0)
            {
                Console.WriteLine("Размер массива должен быть положительным числом.");
                return new int[0]; // Возвращаем пустой массив
            }

            int[] arr = new int[n];
            Console.WriteLine("Введите элементы массива:");
            for (int i = 0; i < n; i++)
            {
                Console.Write($"Элемент {i + 1}: ");
                string inputElement = Console.ReadLine();
                if (int.TryParse(inputElement, out arr[i]))
                {
                    // Значение присвоено
                }
                else
                {
                    Console.WriteLine("Некорректный ввод элемента. Установлено значение 0.");
                    arr[i] = 0;
                }
            }
            return arr;
        }

        public static int ProcessArray(int[] arr)
        {
            if (arr == null || arr.Length < 3)
            {
                return 0;
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

        public static void OutputArray(int[] arr, int result)
        {
            if (arr == null || arr.Length == 0)
            {
                Console.WriteLine("Массив не был корректно инициализирован.");
                return;
            }
            Console.WriteLine("Массив: [" + string.Join(", ", arr) + "]");
            Console.WriteLine("Количество локальных максимумов: " + result);
        }

        public static void Main(string[] args) // Измените имя одного из Main на другое, если все в одном проекте
        {
            int[] arr = InputArray();
            if (arr.Length > 0)
            {
                int localMaximaCount = ProcessArray(arr);
                OutputArray(arr, localMaximaCount);
            }
        }
    }
}