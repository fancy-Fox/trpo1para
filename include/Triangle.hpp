#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class Triangle {
public:
    pair<double, double> vertex0;
    pair<double, double> vertex1;
    pair<double, double> vertex2;
    vector<double> coordArr;
    double sideA;
    double sideB;
    double sideC;
    double triangleP;
    double trianglepol;
    double triangleA;

    Triangle(vector<double> coord) {
        this->coordArr = coord;
        this->vertex0 = make_pair(coordArr[0], coordArr[1]);
        this->vertex1 = make_pair(coordArr[2], coordArr[3]);
        this->vertex2 = make_pair(coordArr[4], coordArr[5]);
        this->sideA = sqrt(pow((vertex1.first - vertex0.first), 2) +
            pow((vertex1.second - vertex0.second), 2));
        this->sideB = sqrt(pow((vertex2.first - vertex1.first), 2) +
            pow((vertex2.second - vertex1.second), 2));
        this->sideC = sqrt(pow((vertex0.first - vertex2.first), 2) +
            pow((vertex0.second - vertex2.second), 2));
        if (!(((sideA + sideB) > sideC) && ((sideA + sideC) > sideB) && ((sideB + sideC) > sideA))) {
            cout << endl << "Error: invalid triangle" << endl;
            exit(0);
        }
        this->triangleP = sideA + sideB + sideC;
        this->trianglepol = triangleP / 2;
        this->triangleA = sqrt(trianglepol * (trianglepol - sideA) * (trianglepol - sideB) * (trianglepol - sideC));
    }

    void tPrint();
};