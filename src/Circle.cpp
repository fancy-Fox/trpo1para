#include "Circle.hpp"

void Circle::cPrint()
{
    cout << "\t"
         << "Radius: " << radius << endl;
    cout << "\t"
         << "Center: " << center.first << " " << center.second << endl;
    cout << "\t"
         << "Perimetr: " << CircleP << endl;
    cout << "\t"
         << "Area: " << CircleA << endl;
}