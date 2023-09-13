#include "controller.h"


void Controller::set_counter(Counter* counter) {
    this->counter = counter;
}

void Controller::clear_counter() {
    delete counter;
}

bool Controller::process_command(char command) {
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
}
