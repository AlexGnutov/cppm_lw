#include <iostream>
#include <string>

#include "greeter.h"
#include "leaver.h"

int main()
{
	setlocale(LC_ALL, "rus");

    std::string name;

    std::cout << "¬ведите им€, месье: ";
    std::cin >> name;

    Greeter gr;

    std::cout << gr.greet(name) << std::endl;

    Leaver lr;

    std::cout << lr.leave(name) << std::endl;

    system("pause");

    return 0;
}