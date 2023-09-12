#include <iostream>

class Shape {
public:
    Shape() {}

    int get_edges() {
        return edges;
    }

protected:
    Shape(int edges) :edges(edges) {}
private:
    int edges = 0;
};

class Triangle : public Shape {
public:
    Triangle() : Shape(3) {}
};

class Quadrangle : public Shape {
public:
    Quadrangle() : Shape(4) {}
};


int main()
{
    setlocale(LC_ALL, "rus");

    Shape shape;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << "Фигура: " << shape.get_edges() << std::endl;
    std::cout << "Треугольник: " << triangle.get_edges() << std::endl;
    std::cout << "Четырёхугольник: " << quadrangle.get_edges() << std::endl;
}
