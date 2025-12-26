#include "rectangle.h"
#include <cmath>

static double cross2(const Point& a, const Point& b)
{
    double v = a.x * b.y - a.y * b.x;
    return v;
}

Rectangle::Rectangle()
{
    p[0] = Point();
    p[1] = Point();
    p[2] = Point();
    p[3] = Point();
}

Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d)
{
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
}

Rectangle::Rectangle(const Rectangle& other)
{
    p[0] = other.p[0];
    p[1] = other.p[1];
    p[2] = other.p[2];
    p[3] = other.p[3];
}

Rectangle::Rectangle(Rectangle&& other) noexcept
{
    p[0] = other.p[0];
    p[1] = other.p[1];
    p[2] = other.p[2];
    p[3] = other.p[3];

    other.p[0] = Point();
    other.p[1] = Point();
    other.p[2] = Point();
    other.p[3] = Point();
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this == &other)
    {
        return *this;
    }

    p[0] = other.p[0];
    p[1] = other.p[1];
    p[2] = other.p[2];
    p[3] = other.p[3];

    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    p[0] = other.p[0];
    p[1] = other.p[1];
    p[2] = other.p[2];
    p[3] = other.p[3];

    other.p[0] = Point();
    other.p[1] = Point();
    other.p[2] = Point();
    other.p[3] = Point();

    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const
{
    if (!(p[0] == other.p[0])) return false;
    if (!(p[1] == other.p[1])) return false;
    if (!(p[2] == other.p[2])) return false;
    if (!(p[3] == other.p[3])) return false;
    return true;
}

double Rectangle::area() const
{
    double sum = 0.0;

    int i = 0;
    while (i < 4)
    {
        int j = i + 1;
        if (j == 4)
        {
            j = 0;
        }

        double add = cross2(p[i], p[j]);
        sum = sum + add;

        i = i + 1;
    }

    double s = sum * 0.5;
    if (s < 0.0)
    {
        s = -s;
    }

    return s;
}

Point Rectangle::center() const
{
    double sum_cross = 0.0;
    double sum_x = 0.0;
    double sum_y = 0.0;

    int i = 0;
    while (i < 4)
    {
        int j = i + 1;
        if (j == 4)
        {
            j = 0;
        }

        double c = cross2(p[i], p[j]);

        sum_cross = sum_cross + c;

        double x_part = (p[i].x + p[j].x) * c;
        double y_part = (p[i].y + p[j].y) * c;

        sum_x = sum_x + x_part;
        sum_y = sum_y + y_part;

        i = i + 1;
    }

    double A = sum_cross * 0.5;
    if (A == 0.0)
    {
        double ax = 0.0;
        double ay = 0.0;

        ax = ax + p[0].x;
        ax = ax + p[1].x;
        ax = ax + p[2].x;
        ax = ax + p[3].x;

        ay = ay + p[0].y;
        ay = ay + p[1].y;
        ay = ay + p[2].y;
        ay = ay + p[3].y;

        Point c0(ax / 4.0, ay / 4.0);
        return c0;
    }

    double denom = 6.0 * A;

    double cx = sum_x / denom;
    double cy = sum_y / denom;

    Point c(cx, cy);
    return c;
}

void Rectangle::print(std::ostream& os) const
{
    os << "Rectangle: ";
    os << p[0] << " ";
    os << p[1] << " ";
    os << p[2] << " ";
    os << p[3];
}

void Rectangle::read(std::istream& is)
{
    is >> p[0];
    is >> p[1];
    is >> p[2];
    is >> p[3];
}

Figure* Rectangle::clone() const
{
    Figure* f = new Rectangle(*this);
    return f;
}

bool Rectangle::equals(const Figure& other) const
{
    const Rectangle* r = dynamic_cast<const Rectangle*>(&other);
    if (r == nullptr)
    {
        return false;
    }

    bool ok = (*this == *r);
    return ok;
}
