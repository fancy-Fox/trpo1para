#pragma once

#include <string>

#include "figure.h"

class Polygon : public Figure {
public:
    Polygon(const std::string&, int);

private:
    int index_;
    std::string type_;
};
