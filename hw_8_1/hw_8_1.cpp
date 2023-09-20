#include <iostream>
#include <exception>

class WrondLengthException : public std::exception
{
public:
    const char* what() const override {
        return "Некорректная длина";
    }
};

int verify_length(const std::string& str, const int& forbidden_length) {
    if (str.length() == forbidden_length) {
        throw WrondLengthException();
    }
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "rus");

    int length = 0;
    std::string str = "";
    
    while (true) {
        std::cout << "Введите длину: ";
        std::cin >> length;
        std::cout << "Введите строку: ";
        std::cin >> str;
        
        try {
            std::cout << "Длина слова \"" << str 
                << "\" равна " << verify_length(str, length) << std::endl;
        } catch (WrondLengthException& err) {
            std::cout << "Вы ввели слово запрещённой длины. До свидания!" << std::endl;
            exit(1);
        }
    }
}
