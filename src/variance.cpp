#include "variance.hpp"

Variance::Variance(const vector<double>& inputData) : data(inputData) {}

double Variance::calculateMean() const {
    if (data.empty()) return 0.0;
    double sum = 0;
    for (double val : data) {
        sum += val;
    }
    return sum / data.size();
}

double Variance::computeVariance() {
    if (data.empty()) return 0.0;
    double mean = calculateMean();
    double variance = 0;
    for (double val : data) {
        variance += (val - mean) * (val - mean);
    }
    return variance / data.size();
}

vector<double> Variance::computeVarianceForMatrix(const vector<vector<rgb>>& rgbMatrix) {
    vector<double> variances;
    for (const auto& row : rgbMatrix) {
        vector<double> channelData;
        for (const auto& pixel : row) {
            channelData.push_back((pixel.getRed() + pixel.getGreen() + pixel.getBlue()) / 3.0);
        }
        Variance var(channelData);
        variances.push_back(var.computeVariance());
    }
    return variances;
}

double Variance::calculateVariance(vector<double>& data) {
    if (data.empty()) return 0.0;
    double mean = 0;
    for (double val : data) {
        mean += val;
    }
    mean /= data.size();
    
    double variance = 0;
    for (double val : data) {
        variance += (val - mean) * (val - mean);
    }
    return variance / data.size();
}

void Variance::printData() const {
    for (double val : data) {
        cout << val << " ";
    }
    cout << endl;
}