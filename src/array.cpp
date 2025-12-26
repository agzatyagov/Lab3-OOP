#include "array.h"

Array::Array()
{
    data = nullptr;
    sz = 0;
}

Array::Array(const Array& other)
{
    data = nullptr;
    sz = 0;

    if (other.sz == 0)
    {
        return;
    }

    data = new Figure * [other.sz];

    std::size_t i = 0;
    while (i < other.sz)
    {
        data[i] = nullptr;
        i = i + 1;
    }

    i = 0;
    while (i < other.sz)
    {
        data[i] = other.data[i]->clone();
        i = i + 1;
    }

    sz = other.sz;
}

Array::Array(Array&& other) noexcept
{
    data = other.data;
    sz = other.sz;

    other.data = nullptr;
    other.sz = 0;
}

Array& Array::operator=(const Array& other)
{
    if (this == &other)
    {
        return *this;
    }

    clear_data();

    if (other.sz == 0)
    {
        return *this;
    }

    data = new Figure * [other.sz];

    std::size_t i = 0;
    while (i < other.sz)
    {
        data[i] = nullptr;
        i = i + 1;
    }

    i = 0;
    while (i < other.sz)
    {
        data[i] = other.data[i]->clone();
        i = i + 1;
    }

    sz = other.sz;

    return *this;
}

Array& Array::operator=(Array&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    clear_data();

    data = other.data;
    sz = other.sz;

    other.data = nullptr;
    other.sz = 0;

    return *this;
}

Array::~Array() noexcept
{
    clear_data();
}

void Array::clear_data()
{
    if (data == nullptr)
    {
        sz = 0;
        return;
    }

    std::size_t i = 0;
    while (i < sz)
    {
        delete data[i];
        data[i] = nullptr;
        i = i + 1;
    }

    delete[] data;
    data = nullptr;
    sz = 0;
}

void Array::push_back(Figure* fig)
{
    if (fig == nullptr)
    {
        return;
    }

    Figure** new_data = new Figure * [sz + 1];

    std::size_t i = 0;
    while (i < sz + 1)
    {
        new_data[i] = nullptr;
        i = i + 1;
    }

    i = 0;
    while (i < sz)
    {
        new_data[i] = data[i];
        i = i + 1;
    }

    new_data[sz] = fig;

    delete[] data;
    data = new_data;

    sz = sz + 1;
}

bool Array::remove(std::size_t index)
{
    if (index >= sz)
    {
        return false;
    }

    delete data[index];
    data[index] = nullptr;

    if (sz == 1)
    {
        delete[] data;
        data = nullptr;
        sz = 0;
        return true;
    }

    Figure** new_data = new Figure * [sz - 1];

    std::size_t i = 0;
    while (i < sz - 1)
    {
        new_data[i] = nullptr;
        i = i + 1;
    }

    std::size_t new_i = 0;
    i = 0;
    while (i < sz)
    {
        if (i != index)
        {
            new_data[new_i] = data[i];
            new_i = new_i + 1;
        }
        i = i + 1;
    }

    delete[] data;
    data = new_data;

    sz = sz - 1;

    return true;
}

std::size_t Array::size() const
{
    return sz;
}

void Array::print_all(std::ostream& os) const
{
    std::size_t i = 0;
    while (i < sz)
    {
        os << "[" << i << "] " << *data[i] << "\n";

        Point c = data[i]->center();
        os << "    center = " << c << "\n";

        double s = (double)(*data[i]);
        os << "    area   = " << s << "\n";

        i = i + 1;
    }
}

double Array::total_area() const
{
    double sum = 0.0;

    std::size_t i = 0;
    while (i < sz)
    {
        double s = (double)(*data[i]);
        sum = sum + s;
        i = i + 1;
    }

    return sum;
}
