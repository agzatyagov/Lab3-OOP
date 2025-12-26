#pragma once

#include <iostream>
#include "figure.h"
#include "point.h"

class Trapezoid : public Figure
{
public:
    Trapezoid();
    Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d);

    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;

    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    bool operator==(const Trapezoid& other) const;

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
    bool equals(const Figure& other) const override;

private:
    Point p[4];
};
