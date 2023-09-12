#include <iostream>
#include <string>
#include <sstream>

class Shape {
public:
    Shape() {}
    int get_number_of_edges() {
        return edges;
    }
    
    virtual std::string get_edges_info() { return ""; };
    virtual std::string get_angles_info() { return ""; };
    
    virtual std::string get_name() { return name; }

protected:
    Shape(int edges) :edges(edges) {}
    
    void set_name(std::string name) {
        this->name = name;
    }
private:
    int edges = 0;
    std::string name;
};

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c, double A, double B, double C) : Shape(3),
        a(a), b(b), c(c), A(A), B(B), C(C) {
        set_name("Треугольник");
    }

    std::string get_edges_info() override {
        std::stringstream ss;
        ss << "a=" << std::to_string(a) << " ";
        ss << "b=" << std::to_string(b) << " ";
        ss << "c=" << std::to_string(c) << " ";
        return ss.str();
    }
    std::string get_angles_info() {
        std::stringstream ss;
        ss << "A=" << std::to_string(A) << " ";
        ss << "B=" << std::to_string(B) << " ";
        ss << "C=" << std::to_string(C) << " ";
        return ss.str();
    }

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
};

//! Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {
        set_name("Равнобедренный треугольник");
    }
};

//! Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {
        set_name("Равносторонний треугольник");
    }
};


class Quadrangle : public Shape {
public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Shape(4),
        a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        set_name("Четырёхугольник");
    }

    std::string get_edges_info() {
        std::stringstream ss;
        ss << "a=" << std::to_string(a) << " ";
        ss << "b=" << std::to_string(b) << " ";
        ss << "c=" << std::to_string(c) << " ";
        ss << "d=" << std::to_string(d) << " ";
        return ss.str();
    }
    std::string get_angles_info() {
        std::stringstream ss;
        ss << "A=" << std::to_string(A) << " ";
        ss << "B=" << std::to_string(B) << " ";
        ss << "C=" << std::to_string(C) << " ";
        ss << "D=" << std::to_string(D) << " ";
        return ss.str();
    }

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
    Rectangle(double a, double b) : Quadrangle(a,b,a,b,90,90,90,90) {
        set_name("Прямоугольник");
    }
};

//! Квадрат
class Square : public Quadrangle {
public:
    Square(double a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        set_name("Квадрат");
    }
};

//! Параллелограм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B) : Quadrangle(a,b,a,b,A,B,A,B) {
        set_name("Параллелограм");
    }
};

//! Ромб
class Rhombus : public Quadrangle {
public:
    Rhombus(double a, double A, double B) : Quadrangle(a, a, a, a, A, B, A, B) {
        set_name("Ромб");
    }
};


void print_info(Shape *shape) {
    std::cout << shape->get_name() << ":" << std::endl;
    std::cout << "Стороны: " << shape->get_edges_info() << std::endl;
    std::cout << "Углы: " << shape->get_angles_info() << std::endl;
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");

    Triangle *tr = new Triangle(1,1,1,60,60,60);
    print_info(tr);
    delete tr;

    RightTriangle *rt = new RightTriangle(3,4,5,30,60);
    print_info(rt);
    delete rt;

    IsoscelesTriangle *ist = new IsoscelesTriangle(2, 3, 30, 120);
    print_info(ist);
    delete ist;

    EquilateralTriangle *etr = new EquilateralTriangle(10);
    print_info(etr);
    delete etr;

    Quadrangle *quad = new Quadrangle(1, 2, 3, 4, 67, 67, 113, 113);
    print_info(quad);
    delete quad;

    Rectangle *rect = new Rectangle(10, 20);
    print_info(rect);
    delete rect;

    Square *square = new Square(25);
    print_info(square);
    delete square;

    Parallelogram *para = new Parallelogram(1,1,100,80);
    print_info(para);
    delete para;

    Rhombus *rhomb = new Rhombus(2, 91, 89);
    print_info(rhomb);
    delete rhomb;

}
