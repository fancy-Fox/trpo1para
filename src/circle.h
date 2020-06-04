#pragma once

#include <string>
#include <vector>

#include "figure.h"

class Circle : public Figure {
public:
    Circle(int);
    Circle(const std::string&, int);

    // implimentation from Figure
    void set_coords(double, double) override;
    void set_radius(double) override;
    double get_radius() override;
    std::string get_type() override;
    std::pair<double, double> get_coords() override;
    int get_index() override;

private:
    double x_;
    double y_;
    double r_;
};