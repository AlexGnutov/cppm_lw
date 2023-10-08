#include <iostream>
#include <string>

#include <leaver.h>

int main()
{
    setlocale(LC_ALL, "rus");

    std::string name;

    std::cout << "Введите имя!!!" << std::endl;
    std::cin >> name;

    Leaver lr;

    std::cout << lr.leave(name) << std::endl;

    system("pause");

    return 0;
}
