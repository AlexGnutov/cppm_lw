#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <io.h>                             // для функции _setmode
#include <fcntl.h>                          // для константы _O_U16TEXT

class Address {
public:
    void set_city(std::string city) { this->city = city; }
    void set_street(std::string street) { this->street = street; }
    void set_house(std::string house) { this->house = house; }
    void set_room(std::string room) { this->room = room; }

    std::string get_city() { return city; }
    std::string get_street() { return street; }
    std::string get_house() { return house; }
    std::string get_room() { return room; }
    
    std::string get_address_string() {
        return  city + ", " + street + ", " + house + ", " + room;
    };

private:
    std::string city;
    std::string street;
    std::string house;
    std::string room;
};

class AddressReader {
public:
    Address read_from_file(std::ifstream& file) {
        Address address;
        std::string buf;
        file >> buf;
        address.set_city(buf);
        file >> buf;
        address.set_street(buf);
        file >> buf;
        address.set_house(buf);
        file >> buf;
        address.set_room(buf);

        return address;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    
    std::ifstream in_file;
    in_file.open("in.txt");
    if (!in_file.is_open()) {
        std::cout << "Не удалось открыть файл данных" << std::endl;
        return -1;
    }

    int qty = 0;
    in_file >> qty;
    if (qty <= 0) {
        std::cout << "Некорректное кол-во адресов: " << qty << std::endl;
        return -1;
    }

    AddressReader adress_reader;
    Address* address_list = new Address[qty];
    for (int i = 0; i < qty; i++) {
        address_list[i] = adress_reader.read_from_file(in_file);
    }
    in_file.close();

    std::ofstream out_file;
    out_file.open("out.txt");
    if (!out_file) {
        std::cout << "Не удалось открыть файл для записи" << std::endl;
        return -1;
    }

    out_file << qty << std::endl;

    for (int i = qty-1; i >= 0; --i) {
        out_file << address_list[i].get_address_string() << std::endl;
    }

    out_file.close();

    delete[] address_list;

    return 0;
}
