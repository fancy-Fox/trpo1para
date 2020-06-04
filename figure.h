#pragma once

#include <string>
class Figure {
public:
    Figure();
    Figure(const std::string&, int);
    std::pair<double, double>
    get_pair_of_numbers(const std::string&, int*, char, char);
    void set_type(const std::string&);
    double get_number(const std::string&, int*, char);

    virtual void set_coords(double, double);
    virtual void set_radius(double);
    virtual double get_radius();
    virtual std::string get_type();
    virtual std::pair<double, double> get_coords();
    virtual int get_index();

protected:
    int index_;
    std::string type_;
};
