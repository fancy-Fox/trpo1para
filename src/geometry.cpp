#include "geometry.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void geometry()
{
    int amountOfFigures = 0;
    vector<string> str;
    string temp = "";
    string fgname = "";

    vector<double> coord;
    stringstream el;

    cout << "Enter the number of figures: ";
    cin >> amountOfFigures;

    for (int i = 0; i <= amountOfFigures; ++i) {
        getline(cin, temp);
        if (temp.length())
            str.push_back(temp);
    }
    cout << endl << endl;

    for (auto temp : str) {
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        cout << temp << ":" << endl;

        if (temp.find("((") != temp.npos) {
            fgname = temp.substr(0, temp.find("(("));
            temp.erase(0, temp.find("((") + 2);
        }
        if (temp.find("(") != temp.npos) {
            fgname = temp.substr(0, temp.find("("));
            temp.erase(0, temp.find("(") + 1);
        }
        if (temp.find("))") != temp.npos) {
            temp.erase(temp.find("))"), temp.size());
        }
        if (temp.find(")") != temp.npos) {
            temp.erase(temp.find(")"), temp.size());
        }

        unsigned int i = 0;

        while (i < temp.size()) {
            while (i < temp.size() && temp[i] != ',') {
                while (i < temp.size() && temp[i] != ' ') {
                    el << temp[i];
                    i++;
                }
                coord.push_back(stod(el.str()));
                el.str().resize(0);
                el.str().clear();
                el.str("");
                i++;
            }
            i++;
        }

        if (fgname == "circle" || fgname == "Circle") {
            Circle circle(coord[2], make_pair(coord[0], coord[1]));
            circle.cPrint();
        } else if (fgname == "triangle" || fgname == "Triangle") {
            Triangle triangle(coord);
            triangle.tPrint();
        } else {
            cout << "Error: unknown shape" << '\'' << fgname << '\'';
        }
        cout << endl;
    }
}
