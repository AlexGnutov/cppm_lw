#include <iostream>

#include "shape.h"
#include "triangle.h"
#include "right_triangle.h"
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"

#include "quadrangle.h"
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"

void print_info(Shape* shape) {
    std::cout << shape->get_name() << ":" << std::endl;
    std::cout << "Стороны: " << shape->get_edges_info() << std::endl;
    std::cout << "Углы: " << shape->get_angles_info() << std::endl;
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Triangle* tr = new Triangle(1, 1, 1, 60, 60, 60);
    print_info(tr);
    delete tr;

    RightTriangle* rt = new RightTriangle(3, 4, 5, 30, 60);
    print_info(rt);
    delete rt;

    IsoscelesTriangle* ist = new IsoscelesTriangle(2, 3, 30, 120);
    print_info(ist);
    delete ist;

    EquilateralTriangle* etr = new EquilateralTriangle(10);
    print_info(etr);
    delete etr;

    Quadrangle* quad = new Quadrangle(1, 2, 3, 4, 67, 67, 113, 113);
    print_info(quad);
    delete quad;

    Rectangle* rect = new Rectangle(10, 20);
    print_info(rect);
    delete rect;

    Square* square = new Square(25);
    print_info(square);
    delete square;

    Parallelogram* para = new Parallelogram(1, 1, 100, 80);
    print_info(para);
    delete para;

    Rhombus* rhomb = new Rhombus(2, 91, 89);
    print_info(rhomb);
    delete rhomb;
}
