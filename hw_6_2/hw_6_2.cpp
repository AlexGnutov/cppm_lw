#include <iostream>
#include <string>
#include <windows.h>

#include "counter.h"
#include "controller.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251); // этот ход подсмотрен в сети

    Controller controller;

    std::string decision;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да, если хотите: " << std::endl;
    std::getline(std::cin, decision);

    if (decision.compare("да") == 0) {
        int init_value;
        std::cout << "Введите начальное значение счётчика: " << std::endl;
        std::cin >> init_value;
        Counter* counter = new Counter(init_value);
        controller.set_counter(counter);
    }
    else {
        Counter* counter = new Counter();
        controller.set_counter(counter);
    }

    char command;
    bool res;

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): " << std::endl;
        std::cin >> command;
        res = controller.process_command(command);

        std::cin.clear();               // сброс флагов ошибок
        std::cin.ignore(1000, '\n');    // очистка буфера

    } while (res);

    controller.clear_counter();
    std::cout << "До свидания!" << std::endl;
}
