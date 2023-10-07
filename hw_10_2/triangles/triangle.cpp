#include "triangle.h"

Triangle::Triangle(double a, double b, double c, double A, double B, double C) : Shape(3),
a(a), b(b), c(c), A(A), B(B), C(C) {
    set_name("Треугольник");
}

std::string Triangle::get_edges_info() {
    std::stringstream ss;
    ss << "a=" << std::to_string(a) << " ";
    ss << "b=" << std::to_string(b) << " ";
    ss << "c=" << std::to_string(c) << " ";
    return ss.str();
}
std::string Triangle::get_angles_info() {
    std::stringstream ss;
    ss << "A=" << std::to_string(A) << " ";
    ss << "B=" << std::to_string(B) << " ";
    ss << "C=" << std::to_string(C) << " ";
    return ss.str();
}