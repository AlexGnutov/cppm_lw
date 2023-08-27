#include <iostream>
#include <string>
#include <cstdint>

struct Address {
    std::string city;
    std::string street;
    std::string house;
    std::string room;
    std::string zip_code;
    void print();
};

void Address::print()
{
    std::cout << "Город: " << city << std::endl;
    std::cout << "Улица: " << street << std::endl;
    std::cout << "Номер дома: " << house<< std::endl;
    std::cout << "Номер квартиры: " << room<< std::endl;
    std::cout << "Индекс: " << zip_code<< std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Address home;
    home.city = "Porto Prenz";
    home.street = "Main street";
    home.house = "12";
    home.room = "10";
    home.zip_code = "123423";

    Address work;
    work.city = "Chelyabinsk";
    work.street = "Lenina";
    work.house = "12";
    work.room = "23";
    work.zip_code = "123423";

    home.print();
    std::cout << "" << std::endl;
    work.print();
}
