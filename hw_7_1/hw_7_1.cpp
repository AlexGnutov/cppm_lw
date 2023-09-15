#include <iostream>

#define MODE 0

#if !defined MODE
    #error "Необходимо определить константу MODE" 
#endif

#if MODE == 1
double add(double a, double b) {
    return a + b;
}
#endif

int main()
{
    setlocale(LC_ALL, "rus");

#if MODE == 0
    std::cout << "Работаю в режиме тренировки." << std::endl;
#elif MODE == 1
    std::cout << "Работаю в боевом режиме." << std::endl;
    
    double a = 0;
    double b = 0;
    
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;

    std::cout << "Результат сложения: " << add(a, b) << std::endl;

#else
    std::cout << "Неизвестный режим. Завершение работы." << std::endl;
#endif


}

