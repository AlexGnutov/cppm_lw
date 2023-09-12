#include <iostream>
#include <string>
#include <sstream>

class Shape {
public:
    Shape() {}

    //! Возвращает количество сторон
    int get_edges() { return edges; }

    //! Возвращает имя фигуры
    std::string get_name() { return name; }
    
    //! Возвращает строку с данными сторон
    virtual std::string get_edges_info() { return ""; }

    //! Возвращает строку с данными углов
    virtual std::string get_angles_info() { return ""; }

    //! Проверяет корректность данных фигуры
    virtual bool is_valid() { return (edges == 0); }

    //! Выводит информацию о фигуре в консоль
    virtual void print_info() { 
        std::cout << get_name() << ":" << std::endl;
        
        std::cout << "Количество сторон: " << get_edges() << std::endl;
        if (is_valid()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }

        std::string edges_info = get_edges_info();
        if (edges_info.length() > 0) {
            std::cout << "Стороны: " << edges_info << std::endl;
        }

        std::string angles_info = get_angles_info();
        if (angles_info.length() > 0) {
            std::cout << "Углы: " << angles_info << std::endl;
        }

        std::cout << std::endl;
    };

protected:
    Shape(int edges) :edges(edges) {}
    
    void set_name(std::string name) {
        this->name = name;
    }
private:
    int edges = 0;
    std::string name = "Фигура";
};

//! Базовый класс треугольников
class Triangle : public Shape {
public:
    Triangle(double a, double b, double c, double A, double B, double C) : Shape(3),
        a(a), b(b), c(c), A(A), B(B), C(C) {
        set_name("Треугольник");
    }

    bool is_valid() override {
        return ((get_edges() == 3) && (A + B + C == 180));
    }

    std::string get_edges_info() override {
        std::stringstream ss;
        ss << "a=" << std::to_string(a) << " ";
        ss << "b=" << std::to_string(b) << " ";
        ss << "c=" << std::to_string(c) << " ";
        return ss.str();
    }
    std::string get_angles_info() override {
        std::stringstream ss;
        ss << "A=" << std::to_string(A) << " ";
        ss << "B=" << std::to_string(B) << " ";
        ss << "C=" << std::to_string(C) << " ";
        return ss.str();
    }

    double get_a() { return a; };
    double get_b() { return b; };
    double get_c() { return c; };
    double get_A() { return A; };
    double get_B() { return B; };
    double get_C() { return C; };

private:
    double a;
    double b;
    double c;
    double A;
    double B;
    double C;
    std::string name;
};

//! Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B) :
        Triangle(a, b, c, A, B, 90) {
        set_name("Прямоугольный треугольник");
    }

    bool is_valid() override {
        return ((get_edges() == 3) && (get_C() == 90));
    }
};

//! Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {
        set_name("Равнобедренный треугольник");
    }

    bool is_valid() override {
        return ((get_a() == get_c()) && (get_A() == get_C()));
    }
};

//! Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        set_name("Равносторонний треугольник");
    }

    bool is_valid() override {
        return ((get_a() == get_b() && get_b() == get_c()) && (get_A() == 60 && get_B() == 60 && get_C() == 60));
    }
};


class Quadrangle : public Shape {
public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Shape(4),
        a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        set_name("Четырёхугольник");
    }

    bool is_valid() override {
        return ((get_edges() == 4) && (A + B + C + D == 360));
    }

    std::string get_edges_info() override {
        std::stringstream ss;
        ss << "a=" << std::to_string(a) << " ";
        ss << "b=" << std::to_string(b) << " ";
        ss << "c=" << std::to_string(c) << " ";
        ss << "d=" << std::to_string(d) << " ";
        return ss.str();
    }
    std::string get_angles_info() override {
        std::stringstream ss;
        ss << "A=" << std::to_string(A) << " ";
        ss << "B=" << std::to_string(B) << " ";
        ss << "C=" << std::to_string(C) << " ";
        ss << "D=" << std::to_string(D) << " ";
        return ss.str();
    }

    double get_a() { return a; };
    double get_b() { return b; };
    double get_c() { return c; };
    double get_d() { return d; };
    double get_A() { return A; };
    double get_B() { return B; };
    double get_C() { return C; };
    double get_D() { return D; };

private:
    double a;
    double b;
    double c;
    double d;
    double A;
    double B;
    double C;
    double D;
    std::string name;
};

//! Прямоугольник
class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        set_name("Прямоугольник");
    }

    bool is_valid() override {
        return ((get_a() == get_c() && get_b() == get_d()) && (get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90));
    }
};

//! Квадрат
class Square : public Quadrangle {
public:
    Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        set_name("Квадрат");
    }

    bool is_valid() override {
        return ((get_a() == get_b() && get_b() == get_c() && get_c() == get_d()) && (get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90));
    }
};

//! Параллелограм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B) {
        set_name("Параллелограм");
    }

    bool is_valid() override {
        return ((get_a() == get_c() && get_b() == get_d()) && (get_A() == get_C() && get_B() == get_D()));
    }
};

//! Ромб
class Rhombus : public Quadrangle {
public:
    Rhombus(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B) {
        set_name("Ромб");
    }

    bool is_valid() override {
        return ((get_a() == get_b() && get_b() == get_c() && get_c() == get_d()) && (get_A() == get_C() && get_B() == get_D()));
    }
};


int main()
{
    setlocale(LC_ALL, "rus");

    Shape* shp = new Shape();
    shp->print_info();
    delete shp;

    Triangle *tr = new Triangle(1, 1, 1, 60, 60, 60);
    tr->print_info();
    delete tr;

    RightTriangle *rt = new RightTriangle(3, 4, 5, 30, 60);
    rt->print_info();
    delete rt;

    IsoscelesTriangle *ist = new IsoscelesTriangle(2, 3, 30, 120);
    ist->print_info();
    delete ist;

    EquilateralTriangle *etr = new EquilateralTriangle(10);
    etr->print_info();
    delete etr;

    Quadrangle *quad = new Quadrangle(1, 2, 3, 4, 67, 67, 113, 113);
    quad->print_info();
    delete quad;

    Rectangle *rect = new Rectangle(10, 20);
    rect->print_info();
    delete rect;

    Square *square = new Square(25);
    square->print_info();
    delete square;

    Parallelogram *para = new Parallelogram(1, 1, 100, 80);
    para->print_info();
    delete para;

    Rhombus *rhomb = new Rhombus(2, 91, 89);
    rhomb->print_info();
    delete rhomb;

}
