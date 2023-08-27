#include <iostream>
#include <string>
#include <cstdint>
#include <sstream>

struct Account {
    std::string owner_name;
    std::uint32_t account_id;
    double balance = 0.0;
    std::string get_info();
};

std::string Account::get_info()
{
    std::stringstream s;
    s << owner_name << ", ";
    s << account_id << ", ";
    s << balance;
    return s.str();
}

bool update_account_balance(Account &account, double value);

int main()
{
    setlocale(LC_ALL, "rus");

    Account account;
    std::cout << "Введите номер счёта: " << std::endl;
    std::cin >> account.account_id;
    std::cout << "Введите имя владельца: " << std::endl;
    std::cin >> account.owner_name;
    std::cout << "Введите баланс: " << std::endl;
    std::cin >> account.balance;

    double new_balance;
    std::cout << "Введите новый баланс: " << std::endl;
    std::cin >> new_balance;
    update_account_balance(account, new_balance);

    std::cout << "Ваш счёт: " << account.get_info() << std::endl;
}

bool update_account_balance(Account& account, double value)
{
    account.balance = value;
    return true;
}