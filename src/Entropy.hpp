#ifndef ENTROPY_HPP
#define ENTROPY_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "rgb.hpp"
using namespace std;


class Entropy {
    private:
        vector<vector<rgb>> imageData;
    public:
        Entropy();
        Entropy(const vector<vector<rgb>>& imgData);
        double calculateEntropy(int width, int height) const;


};
#endif