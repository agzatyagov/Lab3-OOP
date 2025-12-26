#pragma once

#include <iostream>
#include "point.h"

class Figure
{
public:
    virtual ~Figure();

    virtual Point center() const = 0;
    virtual double area() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual Figure* clone() const = 0;
    virtual bool equals(const Figure& other) const = 0;

    operator double() const;

    bool operator==(const Figure& other) const;
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

Figure* sozdat_figuru_po_tipu(int tip);
