#pragma once

#include <string>
#include <sstream>

#include "shape.h"

class Triangle : public Shape {
public:
    Triangle(double a, double b, double c, double A, double B, double C);

    std::string get_edges_info() override;
    std::string get_angles_info() override;

private:
    double a;
    double b;
    double c;
    double A;
    double B;
    double C;
    std::string name;
};
