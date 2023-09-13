#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {
	set_name("Равнобедренный треугольник");
}
