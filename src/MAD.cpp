#include "mad.hpp"

MAD::MAD(const std::vector<double>& inputData) : data(inputData) {}

double MAD::calculateMean() const {
    double sum = 0;
    for (double value : data) {
        sum += value;
    }
    return sum / data.size();
}

double MAD::computeMAD() {
    double mean = calculateMean();
    double mad = 0.0;
    for (double value : data) {
        mad += abs(value - mean);
    }
    return mad / data.size();
}

vector<double> MAD::computeMADForMatrix(const vector<vector<rgb>>& rgbMatrix) {
    vector<double> madValues(3, 0.0);

    vector<double> redValues;
    vector<double> greenValues;
    vector<double> blueValues;

    for (const auto& row : rgbMatrix) {
        for (const auto& pixel : row) {
            redValues.push_back(pixel.getRed());
            greenValues.push_back(pixel.getGreen());
            blueValues.push_back(pixel.getBlue());
        }
    }

    MAD redMAD(redValues);
    MAD greenMAD(greenValues);
    MAD blueMAD(blueValues);

    madValues[0] = redMAD.computeMAD();
    madValues[1] = greenMAD.computeMAD();
    madValues[2] = blueMAD.computeMAD();

    return madValues;
}

double MAD::calculateMAD(vector<double>& data) {
    double mad = 0.0;
    for (double value : data) {
        mad += abs(value);
    }
    return mad / data.size();
}
void MAD::printData() const {
    cout << "Data: ";
    for (double value : data) {
        cout << value << " ";
    }
    cout << endl;
}
