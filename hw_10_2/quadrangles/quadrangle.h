#pragma once

#include <sstream>

#include "shape.h"

class Quadrangle : public Shape {
public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D);

    std::string get_edges_info() override;
    std::string get_angles_info() override;

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
