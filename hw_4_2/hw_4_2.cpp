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

class AddressBook {
public:
    AddressBook(int size) {
        this->list = new Address[size];
        this->size = size;
    }
    
    ~AddressBook() {
        delete[] list;
    }

    bool set_value(Address address, int idx) {
        if (idx < 0 || idx >= size) {
            std::cout << "Указанный индекс превышает размеры адресной книги" << std::endl;
            return false;
        }
        list[idx] = address;
        return true;
    }

    void sort() {
        for (int i = 0; i < size-1; ++i) {
            int smallest_idx = i;
            for (int j = i+1; j < size; ++j) {
                if (compare(list[smallest_idx], list[j])) {
                    smallest_idx = j;
                }
            }
            Address tmp = list[i];
            list[i] = list[smallest_idx];
            list[smallest_idx] = tmp;
        }
    }
    bool save_to_file(std::string path) {
        std::ofstream file;
        file.open(path);
        if (!file.is_open()) {
            std::cout << "Не удалось открыть файл для записи" << std::endl;
            return false;
        }

        file << size << std::endl;
        for (int i = 0; i < size; ++i) {
            file << list[i].get_address_string() << std::endl;
        }
        file.close();
    }
    
private:
    bool compare(Address address_1, Address address_2) {
        return (address_1.get_city().compare(address_2.get_city()) > 0);
    }

    Address* list;
    int size;
};

int main()
{
    std::string in_file_path = "in.txt";
    std::string out_file_path = "out.txt";

    setlocale(LC_ALL, "rus");

    std::ifstream in_file;
    in_file.open(in_file_path);
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
    AddressBook address_book(qty);
    for (int i = 0; i < qty; i++) {
        address_book.set_value(adress_reader.read_from_file(in_file), i);
    }
    in_file.close();

    address_book.sort();
    address_book.save_to_file(out_file_path);

    return 0;
}
