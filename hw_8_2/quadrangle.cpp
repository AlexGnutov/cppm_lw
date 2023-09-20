#include "quadrangle.h"
#include "creation_errors.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : Shape(4),
    a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {

    if (A + B + C + D != 360) {
        throw QuadrangleAngleSumException();
    }

    set_name("Четырёхугольник");
}

std::string Quadrangle::get_edges_info() {
    std::stringstream ss;
    ss << "a=" << std::to_string(a) << " ";
    ss << "b=" << std::to_string(b) << " ";
    ss << "c=" << std::to_string(c) << " ";
    ss << "d=" << std::to_string(d) << " ";
    return ss.str();
}

std::string Quadrangle::get_angles_info() {
    std::stringstream ss;
    ss << "A=" << std::to_string(A) << " ";
    ss << "B=" << std::to_string(B) << " ";
    ss << "C=" << std::to_string(C) << " ";
    ss << "D=" << std::to_string(D) << " ";
    return ss.str();
}
