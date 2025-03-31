// blok.hpp
#ifndef BLOK_HPP
#define BLOK_HPP
#include <iostream>
#include <string>
using namespace std;

class Blok
{
    private:
    const int coordX;
    const int coordY;
    static int countBlok;
    matrix<rgb> image;
}

#endif