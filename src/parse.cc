#include "parse.h"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string parse_type(const std::string& input, int* position, char delimer)
{
    std::string res;
    while (*position < (int)input.size() && input[*position] != delimer) {
        res += input[*position];
        *position += 1;
    }
    *position += 1;
    return res;
}