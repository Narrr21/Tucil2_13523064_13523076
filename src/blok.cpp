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

bool Blok::checkSeragam(int method, int range) const {
    if(method == 1) {
        Variance varianceCalc({});
        vector<double> variance = varianceCalc.computeVarianceForMatrix(image);
        double var = varianceCalc.calculateVariance(variance);
        if (var < range) {
            return true;
        }
    } else if(method == 2) {
        MAD madvalue({});
        vector<double> madval = madvalue.computeMADForMatrix(image);
        double mad = madvalue.calculateMAD(madval);
        if (mad < range) {
            return true;
        }
    } else if(method == 3) {
        MPD mpdCalc(image);
        double mpd = mpdCalc.computeMPD();
        if (mpd < range) {
            return true;
        }
    } else if(method == 4) {
        Entropy entropy(image);
        double ent = entropy.calculateEntropy(sizeX, sizeY);
        if (ent < range) {
            return true;
        }
    } else {
        return false;
    }
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    return false;
}

bool Blok::divide(int method, int range, int minBlok) {

    if (checkSeragam(method, range)) {
        isRoot = false;
        return false;
    }

    if (sizeX / 2 < minBlok || sizeY / 2 < minBlok) {
        isRoot = false;
        return false;
    }

    int halfX = sizeX / 2 + (sizeX % 2);
    int halfY = sizeY / 2 + (sizeY % 2);

    vector<vector<rgb>> img1(halfY, vector<rgb>(halfX));
    vector<vector<rgb>> img2(halfY, vector<rgb>(sizeX - halfX));
    vector<vector<rgb>> img3(sizeY - halfY, vector<rgb>(halfX));
    vector<vector<rgb>> img4(sizeY - halfY, vector<rgb>(sizeX - halfX));

    for (int i = 0; i < halfY; i++) {
        for (int j = 0; j < halfX; j++) {
            img1[i][j] = image[i][j];
            if (j + halfX < sizeX) {
                img2[i][j] = image[i][j + halfX];
            }
        }
    }

    for (int i = 0; i < sizeY - halfY; i++) {
        for (int j = 0; j < halfX; j++) {
            img3[i][j] = image[i + halfY][j];
            if (j + halfX < sizeX) {
                img4[i][j] = image[i + halfY][j + halfX];
            }
        }
    }

    children[0] = new Blok(coordX, coordY, img1, halfX, halfY, depth + 1);
    children[1] = new Blok(coordX + halfX, coordY, img2, sizeX - halfX, halfY, depth + 1);
    children[2] = new Blok(coordX, coordY + halfY, img3, halfX, sizeY - halfY, depth + 1);
    children[3] = new Blok(coordX + halfX, coordY + halfY, img4, sizeX - halfX, sizeY - halfY, depth + 1);

    for (int i = 0; i < 4; i++) {
        children[i]->divide(method, range, minBlok);
    }

    return true;
}


void Blok::normalizeRGB() {
    if (!isRoot) {
        int totalRed = 0, totalGreen = 0, totalBlue = 0;
        int pixelCount = sizeX * sizeY;


        for (auto& row : image) {
            for (auto& pixel : row) {
                totalRed += pixel.getRed();
                totalGreen += pixel.getGreen();
                totalBlue += pixel.getBlue();
            }
        }

        int avgRed = totalRed / pixelCount;
        int avgGreen = totalGreen / pixelCount;
        int avgBlue = totalBlue / pixelCount;

        for (auto& row : image) {
            for (auto& pixel : row) {
                pixel.setRed(avgRed);
                pixel.setGreen(avgGreen);
                pixel.setBlue(avgBlue);
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (children[i] != nullptr) {
            children[i]->normalizeRGB();
        }
    }
}


void Blok::reconstructMatrix(vector<vector<rgb>>& outputMatrix) {
    if (!isRoot) {
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                outputMatrix[coordY + i][coordX + j] = image[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        if (children[i] != nullptr) {
            children[i]->reconstructMatrix(outputMatrix);
        }
    }
}

void Blok::printBlok(int level) const {
    for (int i = 0; i < level; i++) {
        cout << "  "; 
    }
    cout << "|-- Blok at (" << coordX << ", " << coordY << "), size: " 
         << sizeX << "x" << sizeY << ", depth: " << depth 
         << (isRoot ? " [INTERNAL NODE]" : " [LEAF]") << endl;

    if (!isRoot) {
        cout << "RGB values at leaf node (" << coordX << ", " << coordY << "): ";
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                cout << "(" << image[i][j].getRed() << ", "
                     << image[i][j].getGreen() << ", "
                     << image[i][j].getBlue() << ") ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (children[i] != nullptr) {
            children[i]->printBlok(level + 1);
        }
    }
}



int Blok::getCountBlok() {
    return countBlok;
}

int Blok::getMaxDepth() {
    return maxDepth;
}