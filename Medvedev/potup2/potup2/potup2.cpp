#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>
#include <locale> 

using namespace std;

// Функция преобразования инфиксного выражения в обратную польскую запись (RPN)
string infixToRPN(const string& expression) {
    stack<char> operators; // Стек для хранения операторов и открывающих скобок
    string output;         // Строка для результата в RPN
    // Карта для хранения приоритетов операторов
    unordered_map<char, int> precedence = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };
    for (int i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        // Пропускаем пробельные символы
        if (isspace(ch)) continue;

        // Если символ - цифра (начало операнда)
        if (isdigit(ch)) {
            string number_str;
            number_str += ch;
            // Читаем все последующие цифры для составления полного числа
            while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
                i++;
                number_str += expression[i];
            }
            output += number_str; // Добавляем полное число в выходную строку
            output += ' ';        // Добавляем пробел как разделитель после операнда
        }
        // Если символ - открывающая скобка
        else if (ch == '(') {
            operators.push(ch); // Помещаем '(' в стек
        }
        // Если символ - закрывающая скобка
        else if (ch == ')') {
            // Извлекаем операторы из стека до тех пор, пока не встретим '('
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top(); // Добавляем оператор из стека в вывод
                output += ' ';             // Добавляем пробел после оператора
                operators.pop();           // Удаляем оператор из стека
            }
            // Если стек не пуст после цикла (значит, нашли '('), удаляем '('
            if (!operators.empty()) {
                operators.pop(); // Удаляем '(' из стека
            }
            // TODO: Можно добавить проверку на случай, если стек опустел (несбалансированные скобки)
        }
        // Если символ - оператор (+, -, *, /)
        else if (precedence.count(ch)) { // Проверяем, есть ли символ в карте приоритетов
            // Пока стек не пуст, на вершине не '(' и приоритет оператора на вершине >= приоритета текущего оператора
            while (!operators.empty() && operators.top() != '(' &&
                precedence.count(operators.top()) &&
                precedence[operators.top()] >= precedence[ch]) {
                output += operators.top(); // Добавляем оператор из стека в вывод
                output += ' ';             // Добавляем пробел
                operators.pop();           // Удаляем оператор из стека
            }
            operators.push(ch); // Помещаем текущий оператор в стек
        }
        // Обработка других символов (переменные, ошибки) - не реализована
    }

    // После обработки всей строки извлекаем все оставшиеся операторы из стека
    while (!operators.empty()) {
        // TODO: Можно добавить проверку на '(' на вершине (несбалансированные скобки)
        output += operators.top();
        output += ' ';
        operators.pop();
    }

    // Удалить последний пробел, если он есть и строка не пуста
    if (!output.empty() && output.back() == ' ') {
        output.pop_back();
    }


    return output;
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    string expression;
    cout << "Введите арифметическое выражение: ";
    getline(cin, expression);

    string rpn = infixToRPN(expression); 
    cout << "Обратная польская запись: " << rpn << endl;

    return 0;
}