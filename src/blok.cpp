#include "blok.hpp"

int Blok::countBlok = 0;
int Blok::maxDepth = 0;

Blok::Blok(int x, int y, int img, int sx, int sy, int d)
    : coordX(x), coordY(y), image(img), sizeX(sx), sizeY(sy), depth(d), isRoot(true) {
    countBlok++;
}

Blok::Blok(const Blok& other)
    : coordX(other.coordX), coordY(other.coordY), image(other.image),
      sizeX(other.sizeX), sizeY(other.sizeY), depth(other.depth), isRoot(other.isRoot) {
    countBlok++;
}

Blok::~Blok() {
    for (int i = 0; i < 4; i++) {
        delete children[i];
    }
    countBlok--;
}

Blok& Blok::operator+(const Blok& other) {
    // Placeholder for merging
    // This should combine the properties of two Blok objects
    // and return a new Blok object.
    return *this;
}

bool Blok::checkSeragam(int method, int range, int minBlok) const {
    // later
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    return true;
}

bool Blok::divide() {

    // placeholder
    int image1, image2, image3, image4;
    image1 = image2 = image3 = image4 = image;
    // placeholder

    int halfX = sizeX / 2;
    int halfY = sizeY / 2;
    children[0] = new Blok(coordX, coordY, image1, halfX, halfY, depth + 1);
    children[1] = new Blok(coordX + halfX, coordY, image2, halfX, halfY, depth + 1);
    children[2] = new Blok(coordX, coordY + halfY, image3, halfX, halfY, depth + 1);
    children[3] = new Blok(coordX + halfX, coordY + halfY, image4, halfX, halfY, depth + 1);
}

int Blok::getCountBlok() {
    return countBlok;
}

int Blok::getMaxDepth() {
    return maxDepth;
}