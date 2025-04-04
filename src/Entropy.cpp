#include "Entropy.hpp"


Entropy::Entropy() : imageData() {}

Entropy::Entropy(const vector<vector<rgb>>& imgData) : imageData(imgData) {}

double Entropy::calculateEntropy(int width, int height) const {
    vector<int> histogramRed(256, 0), histogramGreen(256, 0), histogramBlue(256, 0);
    double totalPixels = width * height;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            histogramRed[imageData[i][j].getRed()]++;
            histogramGreen[imageData[i][j].getGreen()]++;
            histogramBlue[imageData[i][j].getBlue()]++;
        }
    }

    double entropyRed = 0.0, entropyGreen = 0.0, entropyBlue = 0.0;
    for(int i = 0; i < 256; i++) {
        if(histogramRed[i] > 0) {
            double p = histogramRed[i] / totalPixels;
            entropyRed -= p * log2(p);
        }
        if(histogramGreen[i] > 0) {
            double p = histogramGreen[i] / totalPixels;
            entropyGreen -= p * log2(p);
        }
        if(histogramBlue[i] > 0) {
            double p = histogramBlue[i] / totalPixels;
            entropyBlue -= p * log2(p);
        }
    }

    return (entropyRed + entropyGreen + entropyBlue) / 3.0;
}