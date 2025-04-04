#ifndef MPD_HPP
#define MPD_HPP

#include <vector>
#include <algorithm>
#include "rgb.hpp"
using namespace std;

class MPD {
private:
    vector<vector<rgb>> data;

public:
    MPD(const vector<vector<rgb>>& imgData);
    double computeMPD() const;
    void printMPD();
};

#endif