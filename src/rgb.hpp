// made a class that holds the RGB values
// rgb.hpp
#ifndef RGB_HPP
#define RGB_HPP
#include <iostream>
#include <string>
using namespace std;

class rgb
{
private:
    int red;
    int green;
    int blue;
public:
    rgb();
    ~rgb();
    rgb(int r, int g, int b);
    rgb(const rgb &other);
    rgb& operator=(const rgb &other);
    rgb& operator+(const rgb &other) const;
    rgb& operator-(const rgb &other) const;
    rgb& operator*(int n) const;
    rgb& operator/(int n) const;
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    // tambahkan fungsi lain yang mungkin dipake di method error Measurement
};

#endif
