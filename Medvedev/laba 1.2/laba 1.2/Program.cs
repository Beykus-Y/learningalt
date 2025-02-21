using System;

public class MatrixSwapper
{
    public static void SwapMatrixQuarters(int[,] matrix)
    {
        int M = matrix.GetLength(0);
        int N = matrix.GetLength(1);

        if (M % 2 != 0 || N % 2 != 0)
        {
            Console.WriteLine("Матрица должна иметь четные размеры (M и N).");
            return;
        }

        int halfM = M / 2;
        int halfN = N / 2;

        // Обмен элементов левой верхней и правой нижней четвертей
        for (int i = 0; i < halfM; i++)
        {
            for (int j = 0; j < halfN; j++)
            {
                int temp = matrix[i, j];
                matrix[i, j] = matrix[i + halfM, j + halfN];
                matrix[i + halfM, j + halfN] = temp;
            }
        }
    }

    public static void PrintMatrix(int[,] matrix)
    {
        int M = matrix.GetLength(0);
        int N = matrix.GetLength(1);

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }

    public static void Main(string[] args)
    {
        int[,] matrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };

        Console.WriteLine("Исходная матрица:");
        PrintMatrix(matrix);

        SwapMatrixQuarters(matrix);

        Console.WriteLine("\nМатрица после обмена четвертей:");
        PrintMatrix(matrix);
    }
}
