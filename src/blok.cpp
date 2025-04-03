#include "blok.hpp"

int Blok::countBlok = 0;
int Blok::maxDepth = 0;

Blok::Blok(int x, int y, vector<vector<rgb>> img, int sx, int sy, int d)
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

bool Blok::checkSeragam(int method, int range) const {
    if(method == 1) {
        // Placeholder for method 1
    } else if(method == 2) {
        // Placeholder for method 2
    } else if(method == 3) {
        // Placeholder for method 3
    } else {
        return false;
    }
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    return true;
}

bool Blok::divide(int method, int range, int minBlok) {

    if (checkSeragam(method, range)) {
        return false;
    }

    if (sizeX / 2 < minBlok || sizeY / 2 < minBlok) {
        return false;
    }

    isRoot = true;

    int halfX = sizeX / 2;
    int halfY = sizeY / 2;

    vector<vector<rgb>> img1(halfY, vector<rgb>(halfX));
    vector<vector<rgb>> img2(halfY, vector<rgb>(halfX));
    vector<vector<rgb>> img3(halfY, vector<rgb>(halfX));
    vector<vector<rgb>> img4(halfY, vector<rgb>(halfX));

    for (int i = 0; i < halfY; i++) {
        for (int j = 0; j < halfX; j++) {
            img1[i][j] = image[i][j];                 // Top-left
            img2[i][j] = image[i][j + halfX];         // Top-right
            img3[i][j] = image[i + halfY][j];         // Bottom-left
            img4[i][j] = image[i + halfY][j + halfX]; // Bottom-right
        }
    }

    children[0] = new Blok(coordX, coordY, img1, halfX, halfY, depth + 1);
    children[1] = new Blok(coordX + halfX, coordY, img2, halfX, halfY, depth + 1);
    children[2] = new Blok(coordX, coordY + halfY, img3, halfX, halfY, depth + 1);
    children[3] = new Blok(coordX + halfX, coordY + halfY, img4, halfX, halfY, depth + 1);

    for (int i = 0; i < 4; i++) {
        children[i]->divide(method, range, minBlok);
    }

    return true;
}

void Blok::printBlok(int level) const {
    for (int i = 0; i < level; i++) {
        cout << "  "; // 2 spaces per level
    }

    // Print block information
    cout << "|-- Blok at (" << coordX << ", " << coordY << "), size: " 
         << sizeX << "x" << sizeY << ", depth: " << depth 
         << (isRoot ? " [INTERNAL NODE]" : " [LEAF]") << endl;

    // Recursively print children
    for (int i = 0; i < 4; i++) {
        if (children[i] != nullptr) {
            children[i]->printBlok(level + 1); // Increase indentation
        }
    }
}


int Blok::getCountBlok() {
    return countBlok;
}

int Blok::getMaxDepth() {
    return maxDepth;
}