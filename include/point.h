#pragma once

#include <iostream>

struct Point
{
    double x;
    double y;

    Point();
    Point(double x_val, double y_val);

    bool operator==(const Point& other) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);
