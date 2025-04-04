#ifndef VARIANCE_HPP
#define VARIANCE_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "rgb.hpp"
using namespace std;

class Variance {
private:
    vector<double> data;

public:
    Variance(const vector<double>& inputData);
    double computeVariance();
    vector<double> computeVarianceForMatrix(const vector<vector<rgb>>& rgbMatrix);
    double calculateMean() const;
    static double calculateVariance(vector<double>& data);
    void printData() const;
};

#endif