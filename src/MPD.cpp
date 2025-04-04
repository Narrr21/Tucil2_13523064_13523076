#include "MPD.hpp"

MPD::MPD(const vector<vector<rgb>>& inputData) : data(inputData) {}

double MPD::computeMPD() const {
    if (data.empty() || data[0].empty()) return 0.0;

    int maxR = 0, maxG = 0, maxB = 0;
    int minR = 255, minG = 255, minB = 255;

    for (const auto& row : data) {
        for (const auto& pixel : row) {
            maxR = max(maxR, pixel.getRed());
            maxG = max(maxG, pixel.getGreen());
            maxB = max(maxB, pixel.getBlue());

            minR = min(minR, pixel.getRed());
            maxG = max(maxG, pixel.getGreen());
            maxB = max(maxB, pixel.getBlue());
        }
    }
    double D_R = maxR - minR;
    double D_G = maxG - minG;
    double D_B = maxB - minB;

    double D_RGB = (D_R + D_G + D_B) / 3.0;

    return D_RGB;
}

void MPD::printMPD() {
    cout << "MPD: " << computeMPD() << endl;
}
