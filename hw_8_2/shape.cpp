#include "shape.h"

Shape::Shape() {}

Shape::Shape(int edges) :edges(edges) {}

int Shape::get_number_of_edges() {
    return edges;
}

std::string Shape::get_edges_info()
{
    return "";
}

std::string Shape::get_angles_info()
{ 
    return "";
}

std::string Shape::get_name() {
    return name;
}

void Shape::set_name(std::string name) {
    this->name = name;
}