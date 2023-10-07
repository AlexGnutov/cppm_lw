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

    bool operator==(const Fraction& fr)
    {
        return (num_ * fr.den_ == fr.num_ * den_);
    }
    bool operator!=(const Fraction& fr)
    {
        return !(*this == fr);
    }

    bool operator>(const Fraction& fr)
    {
        return (num_ * fr.den_ > fr.num_ * den_);
    }
    bool operator<=(const Fraction& fr)
    {
        return !(*this > fr);
    }

    bool operator<(const Fraction& fr)
    {
        return (num_ * fr.den_ < fr.num_ * den_);
    }
    bool operator>=(const Fraction& fr)
    {
        return !(*this < fr);
    }

};


int main()
{
    std::cout << "HW 9 1\n";

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << std::endl;
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << std::endl;
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << std::endl;
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << std::endl;
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << std::endl;
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << std::endl;

    return 0;

}
