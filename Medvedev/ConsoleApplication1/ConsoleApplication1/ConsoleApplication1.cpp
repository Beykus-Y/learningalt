// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


int main()
{
    int a;
    float b;
    std::cin >> a;
    std::cin >> b;

    if (a == b) {
        std::cout << "Yeah\n";
    }
    else
    {
        std::cout << "No";
    }

}
