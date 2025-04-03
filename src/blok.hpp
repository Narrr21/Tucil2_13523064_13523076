#ifndef BLOK_HPP
#define BLOK_HPP

#include <iostream>
#include <string>
using namespace std;

class Blok {
private:
    const int coordX;
    const int coordY;
    static int countBlok;
    static int maxDepth;
    const int sizeX;
    const int sizeY;
    bool isRoot;
    int image; // Placeholder, perlu matrix RGB
    int depth;

    Blok* children[4] = {nullptr, nullptr, nullptr, nullptr};

public:
    Blok(int x, int y, int img, int sx, int sy, int d = 0);
    Blok(const Blok& other);
    ~Blok();
    Blok& operator+(const Blok& other);

    bool checkSeragam(int method, int range, int minBlok) const;
    bool divide();
    
    static int getCountBlok();
    static int getMaxDepth();
};

#endif