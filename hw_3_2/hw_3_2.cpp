#include <iostream>
#include <string>
#include <windows.h>

class Counter {
public:
    Counter() {};
    Counter(int init_value) :value(init_value) {};

    void increment() {
        ++value;
    };
    void decrement() {
        --value;
    }
    int get_value() {
        return value;
    }
private:
    int value = 1;
};

class Controller {
public:
    void set_counter(Counter* counter) {
        this->counter = counter;
    }
    void clear_counter() {
        delete counter;
    }

    bool process_command(char command) {
        switch (command) {
        case '+': {
            counter->increment();
            break;
        }
        case '-': {
            counter->decrement();
            break;
        }
        case '=': {
            std::cout << counter->get_value() << std::endl;
            break;
        }
        case 'x': {
            return false;
        }
        default: {
            std::cout << "Неизвестная команда" << std::endl;
        }
        }
        return true;
    };

private:
    Counter *counter;
};

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
    } else {
        Counter* counter = new Counter();
        controller.set_counter(counter);
    }

    char command;
    bool res;

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): " << std::endl;
        std::cin >> command;
        res = controller.process_command(command);
    } while (res);

    controller.clear_counter();
    std::cout << "До свидания!" << std::endl;
}
