#pragma once

#include <string>

class Shape {
public:
    Shape();
    int get_number_of_edges();

    virtual std::string get_edges_info();
    virtual std::string get_angles_info();
    virtual std::string get_name();

protected:
    Shape(int edges);

    void set_name(std::string name);

private:
    int edges = 0;
    std::string name;
};