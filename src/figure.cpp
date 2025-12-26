#include "figure.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"

Figure::~Figure()
{
}

Figure::operator double() const
{
    double s = area();
    return s;
}

bool Figure::operator==(const Figure& other) const
{
    bool ok = equals(other);
    return ok;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig)
{
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig)
{
    fig.read(is);
    return is;
}

Figure* sozdat_figuru_po_tipu(int tip)
{
    if (tip == 1)
    {
        Figure* f = new Rectangle();
        return f;
    }
    if (tip == 2)
    {
        Figure* f = new Trapezoid();
        return f;
    }
    if (tip == 3)
    {
        Figure* f = new Rhombus();
        return f;
    }

    return nullptr;
}
