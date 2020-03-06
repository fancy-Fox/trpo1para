#include <iostream>
#include <vector>
#include <string>
#include <cmath>


#include "circle.h"
#include "polygon.h"

std::string parse_type(const std::string& input, int* position, char delimer) {
	std::string res;
	while(*position < input.size() && input[*position] != delimer) {
		res += input[*position];
		*position += 1;
	}
	*position += 1;
	return res;
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1-y2) * fabs(y1-y2));
}

int main() {
	std::vector<Figure> figures;
	int index = 1;
	while (1) {
		std::string input = "Circle(13 14, 5)"; // example
		getline(std::cin, input);
		if (input == "Exit" or input == "exit") {
			break;
		}
		int position = 0;
		std::string type = parse_type(input, &position, '(');
		if (type == "Circle") {
			figures.push_back(Circle(index));
			std::pair<double, double> point = figures.back().get_pair_of_numbers(input, &position, ' ', ',');
			if (point.second == -1) {
				figures.erase(prev(figures.end()));
				std::cout << "Incorrect point.\nFollow this type: Circle(x y, r)\n";
				continue;
			}
			figures.back().set_coords(point.first, point.second);
			double radius = figures.back().get_number(input, &position, ')');
			if (radius == -1) {
				figures.erase(prev(figures.end()));
				std::cout << "Incorrect radius.\nFollow this type: Circle(x y, r)\n";
				continue;
			}
			figures.back().set_radius(radius);
		} else if (type == "Polygon") {

		} else {
			std :: cout << "Incorrect type of figure\nTry Circle or Polygon next time\n";
			continue;
		}
		++index;
	}
	std::vector<std::pair<int,int>> crossed_figures;
	for (auto& i : figures) {
		std:: cout << i.get_coords().first << " " << i.get_coords().second << " " << i.get_radius() << std::endl;
	}
	for (int i = 0; i < figures.size(); ++i) {
		for (int j = i + 1; j < figures.size(); ++j) {
			if (figures[i].get_type() == "Circle" and figures[j].get_type() == "Circle") {
				std::pair<double, double> a = figures[i].get_coords(), b = figures[j].get_coords();
				if (figures[i].get_radius() + figures[j].get_radius() >= dist(a.first,a.second,b.first,b.second)) {
					crossed_figures.emplace_back(figures[i].get_index(), figures[j].get_index());
				}
			}
		}
	}
	for (auto& i : crossed_figures) {
		std::cout << "Figure " << i.first << " cross figure " << i.second << ".\n";
	}
	system("PAUSE");
}