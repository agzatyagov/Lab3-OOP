#pragma once

#include <iostream>
#include "figure.h"
#include "point.h"

class Rhombus : public Figure
{
public:
    Rhombus();
    Rhombus(const Point& a, const Point& b, const Point& c, const Point& d);

    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;

    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;

    bool operator==(const Rhombus& other) const;

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
    bool equals(const Figure& other) const override;

private:
    Point p[4];
};
