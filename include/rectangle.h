#pragma once

#include <iostream>
#include "figure.h"
#include "point.h"

class Rectangle : public Figure
{
public:
    Rectangle();
    Rectangle(const Point& a, const Point& b, const Point& c, const Point& d);

    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;

    bool operator==(const Rectangle& other) const;

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
    bool equals(const Figure& other) const override;

private:
    Point p[4];
};
