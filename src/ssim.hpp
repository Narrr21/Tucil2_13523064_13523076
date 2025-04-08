#ifndef SSIM_HPP
#define SSIM_HPP

#include <vector>
#include <cmath>
#include <iostream>
#include "rgb.hpp"

using namespace std;

class SSIM { 
private:
    vector<vector<rgb>> data;
    vector<vector<unsigned char>> R;
    vector<vector<unsigned char>> G;
    vector<vector<unsigned char>> B;
    double C1 = 6.5025, C2 = 58.5225, WR = 0.299, WG = 0.587, WB = 0.114;
public:
    SSIM(const vector<vector<rgb>>& inputData) : data(inputData) {
        int H = data.size();
        int W = data[0].size();
        R.resize(H, vector<unsigned char>(W));
        G.resize(H, vector<unsigned char>(W));
        B.resize(H, vector<unsigned char>(W));
        
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                R[i][j] = data[i][j].getRed();
                G[i][j] = data[i][j].getGreen();
                B[i][j] = data[i][j].getBlue();
            }
        }
    }

    double computeSSIMChannel(const vector<vector<unsigned char>>& ori, unsigned char compressedValue);
    double computeSSIM(const rgb& compressedColor);
    void debugPrint();
};

#endif