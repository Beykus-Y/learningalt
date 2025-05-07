using System;
using System.IO;
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
                        result.Append(spaceCount % 2 == 0 ? 'Ч' : 'Н');
                        spaceCount = 0;
                    }
                    result.Append(currentChar);
                }
            }

            if (spaceCount > 0)
            {
                result.Append(spaceCount % 2 == 0 ? 'Ч' : 'Н');
            }

            return result.ToString();
        }

        public static void Main(string[] args)
        {
            string filePath = @"C:\test\input.txt";

            if (!File.Exists(filePath))
            {
                Console.WriteLine("Файл не найден: " + filePath);
                return;
            }

            string content = File.ReadAllText(filePath, Encoding.UTF8);

            Console.WriteLine("Исходная строка: " + content);

            string processedContent = ProcessStringWithSpaces(content);
            Console.WriteLine("Обработанная строка: " + processedContent);
        }
    }
}
