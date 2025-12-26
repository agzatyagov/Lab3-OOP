#pragma once

#include <cstddef>
#include <iostream>
#include "figure.h"

class Array
{
public:
    Array();
    Array(const Array& other);
    Array(Array&& other) noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    ~Array() noexcept;

    void push_back(Figure* fig);
    bool remove(std::size_t index);

    std::size_t size() const;

    void print_all(std::ostream& os) const;
    double total_area() const;

private:
    Figure** data;
    std::size_t sz;

private:
    void clear_data();
};
