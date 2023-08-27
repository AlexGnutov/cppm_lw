#include <iostream>
#include <string>

enum months
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

std::string get_month(months month);

int main()
{
    setlocale(LC_ALL, "rus");

    int input;

    do {
        std::cout << "Введите номер месяца: " << std::endl;
        std::cin >> input;
        if (input != 0) {
            std::cout << get_month(static_cast<months>(input)) << std::endl;
        }
    } while (input != 0);
    std::cout << "До свидания!" << std::endl;
}

std::string get_month(months month)
{
    switch (month)
    {
    case jan:
        return "Январь";
        break;
    case feb:
        return "Февраль";
        break;
    case mar:
        return "Март";
        break;
    case apr:
        return "Апрель";
        break;
    case may:
        return "Май";
        break;
    case jun:
        return "Июнь";
        break;
    case jul:
        return "Июль";
        break;
    case aug:
        return "Август";
        break;
    case sep:
        return "Сентябрь";
        break;
    case oct:
        return "Октябрь";
        break;
    case nov:
        return "Ноябрь";
        break;
    case dec:
        return "Декабрь";
        break;
    default:
        return "Неправильный номер!";
        break;
    }
}
