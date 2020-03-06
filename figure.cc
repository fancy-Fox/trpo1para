#include "figure.h"

Figure::Figure() {
	index_ = 0;
	type_ = "unknown";
}

Figure::Figure(const std::string& input, int index) {
	index_ = index;
}

std::pair<double, double> Figure::get_pair_of_numbers(const std::string& input, int* position, char first_delimer, char second_delimer) {
	std::pair<double, double> res = {0, 0};
	bool is_ready = false;
	while (*position < input.size() && input[*position] != second_delimer) {
		if (input[*position] == first_delimer) {
			*position += 1;
			is_ready = true;
			continue;
		}
		if (input[*position] < '0' or input[*position] > '9') {
			return {-1, -1};
		}
		if (is_ready) {
			res.second = res.second * 10 + input[*position] - '0';
		} else {
			res.first = res.first * 10 + input[*position] - '0';
		}
		*position += 1;
	}
	*position += 2;
	return res;
}

double Figure::get_number(const std::string& input, int* position, char delimer) {
	double res = 0.;
	while (*position < input.size() && input[*position] != delimer) {
		if (input[*position] < '0' or input[*position] > '9') {
			return -1;
		}
		res = res * 10 + input[*position] - '0';
		*position += 1;
	}
	return res;
}

void Figure::set_type(const std::string& type) {
	type_ = type;
}

void Figure::set_coords(double x, double y) {

}


void Figure::set_radius(double r) {

}


double Figure::get_radius() {

}


std::string Figure::get_type() {

}

std::pair<double, double> Figure::get_coords() {

}


int Figure::get_index() {
	
}
