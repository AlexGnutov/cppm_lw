#include "right_triangle.h"

RightTriangle::RightTriangle(double a, double b, double c, double A, double B) :
    Triangle(a, b, c, A, B, 90) {
    set_name("Прямоугольный треугольник");
}