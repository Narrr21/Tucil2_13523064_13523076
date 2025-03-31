#include "rgb.hpp"

rgb::rgb()
{
    red = 0;
    green = 0;
    blue = 0;
}
rgb::~rgb() {}

rgb::rgb(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

rgb::rgb(const rgb &other)
{
    red = other.red;
    green = other.green;
    blue = other.blue;
}

rgb& rgb::operator=(const rgb &other)
{
    if (this != &other)
    {
        red = other.red;
        green = other.green;
        blue = other.blue;
    }
    return *this;
}

rgb& rgb::operator+(const rgb &other) const
{
    return rgb(red + other.red, green + other.green, blue + other.blue);
}

rgb& rgb::operator-(const rgb &other) const
{
    return rgb(red - other.red, green - other.green, blue - other.blue);
}

rgb& rgb::operator*(int n) const
{
    return rgb(red * n, green * n, blue * n);
}

rgb& rgb::operator/(int n) const
{
    if (n == 0)
    {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return rgb(red / n, green / n, blue / n);
}

int rgb::getRed() const
{
    return red;
}
int rgb::getGreen() const
{
    return green;
}
int rgb::getBlue() const
{
    return blue;
}
void rgb::setRed(int r)
{
    red = r;
}
void rgb::setGreen(int g)
{
    green = g;
}
void rgb::setBlue(int b)
{
    blue = b;
}