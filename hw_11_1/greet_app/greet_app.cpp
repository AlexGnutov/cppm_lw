#include <iostream>
#include <string>

#include <greeter.h>

int main()
{
    setlocale(LC_ALL, "rus");

    std::string name;

    std::cout << "Введите имя, месье: ";
    std::cin >> name;

    Greeter gr;

    std::cout << gr.greet(name) << std::endl;

    system("pause");

    return 0;
}
