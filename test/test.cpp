#include "figure.h"
#include "geometry.h"
#include <gtest/gtest.h>


TEST(INPUT, correctParseTypeOfFigure) {
    std::string input = "Circle(13 14, 5)";
    int pos = 0;
    ASSERT_STREQ(parse_type(input, pos, '('), "Circle");
    ASSERT_EQ(pos, 6);
}


TEST(INPUT, incorrectParseTypeOfFigure) {
    std::string input = "(Circle(13 14, 5)";
    int pos = 0;
    std::string res = parse_type(input, pos, '(');
    ASSERT_STREQ(res, "");
    ASSERT_EQ(pos, 0);
}
