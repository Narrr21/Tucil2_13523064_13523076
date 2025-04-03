#ifndef MAD_HPP
#define MAD_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "rgb.hpp"
using namespace std;

class MAD {
private:
    vector<double> data;

public:
    MAD(const std::vector<double>& inputData);
    double computeMAD();
    std::vector<double> computeMADForMatrix(const std::vector<std::vector<rgb>>& rgbMatrix);
    double calculateMean() const;
    static double calculateMAD(vector<double> &data);
    void printData() const;
};

#endif
