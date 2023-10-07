#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "rus");

	std::string name;

	std::cout << "Введите ваше имя, сэр: ";
	std::cin >> name;

	std::cout << "Рады приветствовать вас, сэр " << name << std::endl;

	system("pause");

	return 0;
}