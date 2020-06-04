#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

const double PI = 3.14159265359;

class Circle {
public:
    double radius;
    pair<double, double> center;
    double CircleP;
    double CircleA;

    Circle(double radius, pair<double, double> center) {
        this->radius = radius;
        this->center = center;
        this->CircleP = radius * 2 * PI;
        this->CircleA = radius * radius * PI;
    }

    void cPrint();
};
