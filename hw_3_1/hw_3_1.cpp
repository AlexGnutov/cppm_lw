#include <iostream>

class Calculator {
public:
    double add() {
        return num1 + num2;
    };
    double multiply() {
        return num1 * num2;
    };
    double substract_1_2() {
        return num1 - num2;
    };
    double substract_2_1() {
        return num2 - num1;
    };
    double divide_1_2() {
        return num1 / num2;
    };
    double divide_2_1() {
        return num2 / num1;
    };
    bool set_num1(double num) {
        if (num != 0) {
            num1 = num;
            return true;
        }
        std::cout << "Неправильный ввод!" << std::endl;
        return false;
    };
    bool set_num2(double num) {
        if (num != 0) {
            num2 = num;
            return true;
        }
        std::cout << "Неправильный ввод!" << std::endl;
        return false;
    };
    void print_results() {
        std::cout << "Результаты вычислений: " << std::endl;
        std::cout << "num1 + num2 = " << add() << std::endl;
        std::cout << "num1 - num2 = " << substract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << substract_2_1() << std::endl;
        std::cout << "num1 / num2 = " << divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << divide_2_1() << std::endl;
        std::cout << "num1 * num2 = " << multiply() << std::endl;
    };
private:
    double num1;
    double num2;
};

int main()
{
    setlocale(LC_ALL, "rus");

    Calculator calculator;

    while (true) {

        double num;
        do {
            std::cout << "Введите первое число (отличное от нуля): " << std::endl;
            std::cin >> num;
        } while (!calculator.set_num1(num));
        do {
            std::cout << "Введите второе число (отличное от нуля): " << std::endl;
            std::cin >> num;
        } while (!calculator.set_num2(num));

        calculator.print_results();
    }
}
