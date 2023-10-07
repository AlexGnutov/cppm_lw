#include "rectangle.h"

Rectangle::Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
	set_name("Прямоугольник");
}