package org.example;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Laba7 {

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
        String filePath = "C:/test/input.txt";
        try {
            String content = new String(Files.readAllBytes(Paths.get(filePath)));
            System.out.println("Исходная строка: " + content);

            String processedContent = processStringWithSpaces(content);
            System.out.println("Обработанная строка: " + processedContent);

        } catch (IOException e) {
            System.out.println("Ошибка при чтении файла: " + e.getMessage());
        }
    }
}
