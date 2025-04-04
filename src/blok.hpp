#ifndef BLOK_HPP
#define BLOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include "rgb.hpp"
#include "MAD.hpp"
#include "Variance.hpp"
#include "Entropy.hpp"
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
    vector<vector<rgb>> image;
    int depth;

    Blok* children[4] = {nullptr, nullptr, nullptr, nullptr};

public:
    Blok(int x, int y, vector<vector<rgb>> img, int sx, int sy, int d = 0);
    Blok(const Blok& other);
    ~Blok();

    bool checkSeragam(int method, int range) const;
    bool divide(int method, int range, int minBlok);
    void normalizeRGB();
    void reconstructMatrix(vector<vector<rgb>>& outputMatrix);

    void printBlok(int level) const;
    
    static int getCountBlok();
    static int getMaxDepth();
};

#endif