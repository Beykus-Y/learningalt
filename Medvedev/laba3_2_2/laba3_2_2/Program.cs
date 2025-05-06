// Laba3_2_2.cs
using System;

namespace org.example
{
    public class Laba3_2_2
    {
        public static int[][] InputMatrix()
        {
            int M, N;
            while (true)
            {
                Console.Write("Введите количество строк M (четное число): ");
                string inputM = Console.ReadLine();
                if (int.TryParse(inputM, out M) && M > 0 && M % 2 == 0)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("M должно быть положительным четным числом.");
                }
            }

            while (true)
            {
                Console.Write("Введите количество столбцов N (четное число): ");
                string inputN = Console.ReadLine();
                if (int.TryParse(inputN, out N) && N > 0 && N % 2 == 0)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("N должно быть положительным четным числом.");
                }
            }

            int[][] matrix = new int[M][];
            for (int i = 0; i < M; i++)
            {
                matrix[i] = new int[N];
            }

            Console.WriteLine("Введите элементы матрицы:");
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    Console.Write($"Элемент [{i}][{j}]: ");
                    string inputElement = Console.ReadLine();
                    if (!int.TryParse(inputElement, out matrix[i][j]))
                    {
                        Console.WriteLine("Некорректный ввод. Установлено значение 0.");
                        matrix[i][j] = 0;
                    }
                }
            }
            return matrix;
        }

        public static void ProcessMatrix(int[][] matrix)
        {
            if (matrix == null || matrix.Length == 0 || matrix[0].Length == 0)
            {
                Console.WriteLine("Матрица пуста или не инициализирована.");
                return;
            }
            int M = matrix.Length;
            int N = matrix[0].Length;

            if (M % 2 != 0 || N % 2 != 0)
            {
                Console.WriteLine("Матрица должна иметь четные размеры (M и N).");
                return;
            }

            int halfM = M / 2;
            int halfN = N / 2;

            for (int i = 0; i < halfM; i++)
            {
                for (int j = 0; j < halfN; j++)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i + halfM][j + halfN];
                    matrix[i + halfM][j + halfN] = temp;
                }
            }
        }

        public static void OutputMatrix(int[][] matrix)
        {
            if (matrix == null || matrix.Length == 0 || matrix[0].Length == 0)
            {
                return;
            }
            for (int i = 0; i < matrix.Length; i++)
            {
                for (int j = 0; j < matrix[i].Length; j++)
                {
                    Console.Write(matrix[i][j] + "\t");
                }
                Console.WriteLine();
            }
        }

        public static void Main(string[] args) // Измените имя
        {
            int[][] matrix = InputMatrix();

            Console.WriteLine("Исходная матрица:");
            OutputMatrix(matrix);

            ProcessMatrix(matrix);

            Console.WriteLine("\nМатрица после обмена четвертей:");
            OutputMatrix(matrix);
        }
    }
}