#include "circle.h"

Circle::Circle(int index) {
	index_ = index;
	type_ = "Circle";
}

void Circle::set_coords(double x, double y) {
	x_ = x, y_ = y;
}


void Circle::set_radius(double r) {
	r_ = r;
}


double Circle::get_radius() {
	return r_;
}

std::string Circle::get_type() {
	return type_;
}


std::pair<double, double> Circle::get_coords() {
	return {x_, y_};
}


int Circle::get_index() {
	return index_;
}
