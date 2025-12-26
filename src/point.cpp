#include "point.h"

Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double x_val, double y_val)
{
    x = x_val;
    y = y_val;
}

bool Point::operator==(const Point& other) const
{
    if (x != other.x)
    {
        return false;
    }
    if (y != other.y)
    {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p)
{
    is >> p.x;
    is >> p.y;
    return is;
}
