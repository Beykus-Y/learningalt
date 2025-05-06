using System;
using System.Text; 

namespace org.example
{
    public class Laba5
    {
        public static string ProcessStringWithSpaces(string input)
        {
            if (string.IsNullOrEmpty(input))
            {
                return "";
            }

            StringBuilder result = new StringBuilder();
            int spaceCount = 0;

            for (int i = 0; i < input.Length; i++)
            {
                char currentChar = input[i];
                if (currentChar == ' ')
                {
                    spaceCount++;
                }
                else
                {
                    if (spaceCount > 0)
                    {
                        if (spaceCount % 2 == 0)
                        {
                            result.Append('Ч');
                        }
                        else
                        {
                            result.Append('Н');
                        }
                        spaceCount = 0;
                    }
                    result.Append(currentChar);
                }
            }
            if (spaceCount > 0)
            {
                if (spaceCount % 2 == 0)
                {
                    result.Append('Ч');
                }
                else
                {
                    result.Append('Н');
                }
            }
            return result.ToString();
        }

        public static void Main(string[] args) // Измените имя
        {
            Console.WriteLine("Введите строку текста:");
            string content = Console.ReadLine();

            Console.WriteLine("Исходная строка: " + content);

            string processedContent = ProcessStringWithSpaces(content);
            Console.WriteLine("Обработанная строка: " + processedContent);
        }
    }
}