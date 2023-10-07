#include <iostream>

class Fraction
{
private:
    int num_;
    int den_;

public:
    Fraction(int num, int den)
    {
        num_ = num;
        den_ = den;
    }

    Fraction operator+(const Fraction& f2)
    {
        if (den_ == f2.den_) {
            return Fraction(num_ + f2.num_, den_);
        }
        else {
            return Fraction(num_ * f2.den_ + f2.num_ * den_, den_ * f2.den_);
        }
    }

    Fraction operator-(const Fraction& f2)
    {
        if (den_ == f2.den_) {
            return Fraction(num_ - f2.num_, den_);
        }
        else {
            return Fraction(num_ * f2.den_ - f2.num_ * den_, den_ * f2.den_);
        }
    }

    Fraction operator*(const Fraction& f2)
    {
        return Fraction(num_ * f2.num_, den_ * f2.den_);
    }
        
    Fraction operator/(const Fraction& f2)
    {
        return Fraction(num_ * f2.den_, den_ * f2.num_);
    }

    Fraction& operator-()
    {
        num_ *= -1;
        return *this;
    }

    Fraction& operator--()
    {
        num_ -= den_;
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    Fraction& operator++()
    {
        num_ += den_;
        return *this;
    }
    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& ios, const Fraction& fr);
};

std::ostream& operator<<(std::ostream& ios, const Fraction& fr)
{
    ios << fr.num_ << "/" << fr.den_;
    return ios;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int fr1_num;
    int fr1_den;
    int fr2_num;
    int fr2_den;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> fr1_num;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> fr1_den;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> fr2_num;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> fr2_den;

    Fraction fr1(fr1_num, fr1_den);
    Fraction fr2(fr2_num, fr2_den);

    std::cout << fr1 << " + " << fr2 << " = " << (fr1 + fr2) << std::endl;
    std::cout << fr1 << " - " << fr2 << " = " << (fr1 - fr2) << std::endl;
    std::cout << fr1 << " * " << fr2 << " = " << (fr1 * fr2) << std::endl;
    std::cout << fr1 << " / " << fr2 << " = " << (fr1 / fr2) << std::endl;

    std::cout << "++" << fr1 << " * " << fr2 << " = " << (++fr1 * fr2) << std::endl;
    std::cout << "Значение дроби 1: " << fr1 << std::endl;

    std::cout << fr1 << "--" << " * " << fr2 << " = " << (fr1-- * fr2) << std::endl;
    std::cout << "Значение дроби 1: " << fr1 << std::endl;
    std::cout << "Значение после унарного минуса: " << -fr1 << std::endl;

}
