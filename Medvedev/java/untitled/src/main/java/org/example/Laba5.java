package org.example;

import java.util.Scanner;

public class Laba5 {

    public static String processStringWithSpaces(String input) {
        if (input == null || input.isEmpty()) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        int spaceCount = 0;

        for (int i = 0; i < input.length(); i++) {
            char currentChar = input.charAt(i);
            if (currentChar == ' ') {
                spaceCount++;
            } else {
                if (spaceCount > 0) {
                    if (spaceCount % 2 == 0) {
                        result.append('Ч');
                    } else {
                        result.append('Н');
                    }
                    spaceCount = 0;
                }
                result.append(currentChar);
            }
        }
        if (spaceCount > 0) {
            if (spaceCount % 2 == 0) {
                result.append('Ч');
            } else {
                result.append('Н');
            }
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите строку текста:");
        String content = scanner.nextLine();

        System.out.println("Исходная строка: " + content);

        String processedContent = processStringWithSpaces(content);
        System.out.println("Обработанная строка: " + processedContent);

        scanner.close();

    }
}