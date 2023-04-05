#include <iostream>
#include <cmath>

#include "Coord.h"

using namespace std;

Coord::Coord()
{
    x = 0;
    y = 0;
}

Coord::Coord(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Coord::norm() const
{
    return sqrt(x*x + y*y);
}

bool Coord::operator==(const Coord &c) const
{
    return (x == c.x && y == c.y);
}

Coord Coord::operator+(const Coord &c) const
{
    return Coord(x + c.x, y + c.y);
}

Coord Coord::operator-(const Coord &c) const
{
    return Coord(x - c.x, y - c.y);
}

Coord& Coord::operator+=(const Coord &c)
{
    x += c.x;
    y += c.y;
    return *this;
}

Coord& Coord::operator-=(const Coord &c)
{
    x -= c.x;
    y -= c.y;
    return *this;
}

Coord Coord::operator*(const float &f) const
{
    return Coord(x * f, y * f);
}

Coord Coord::operator/(const float &f) const
{
    return Coord(x / f, y / f);
}

Coord& Coord::operator*=(const float &f)
{
    x *= f;
    y *= f;
    return *this;
}

Coord& Coord::operator/=(const float &f)
{
    x /= f;
    y /= f;
    return *this;
}

float & Coord::operator[](int dim) {
    if (dim == 0) {
        return x;
    } else if (dim == 1) {
        return y;
    } else {
        throw "Coord::operator[]: index out of bounds";
    }
}

float Coord::operator[](int dim) const {
    if (dim == 0) {
        return x;
    } else if (dim == 1) {
        return y;
    } else {
        throw "Coord::operator[]: index out of bounds";
    }
}