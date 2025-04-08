#include "ssim.hpp"

double SSIM::computeSSIMChannel(const vector<vector<unsigned char>>& ori, unsigned char compressedValue) {
    double meanOri = 0.0;
    double meanCmp = static_cast<double>(compressedValue);
    double varOri = 0.0;
    double covar = 0.0;
    int count = 0;

    for (size_t i = 0; i < ori.size(); ++i) {
        for (size_t j = 0; j < ori[i].size(); ++j) {
            meanOri += ori[i][j];
            count++;
        }
    }

    meanOri /= count;

    for (size_t i = 0; i < ori.size(); ++i) {
        for (size_t j = 0; j < ori[i].size(); ++j) {
            varOri += pow(ori[i][j] - meanOri, 2);
            covar += (ori[i][j] - meanOri) * (compressedValue - meanCmp);
        }
    }

    varOri /= count;
    covar /= count;

    double ssim = ((2 * meanOri * meanCmp + C1) * (2 * covar + C2)) /
                  ((pow(meanOri, 2) + pow(meanCmp, 2) + C1) * (varOri + C2));

    return ssim;
}

double SSIM::computeSSIM(const rgb& compressedColor) {
    double ssimR = computeSSIMChannel(R, compressedColor.getRed());
    double ssimG = computeSSIMChannel(G, compressedColor.getGreen());
    double ssimB = computeSSIMChannel(B, compressedColor.getBlue());

    return WR * ssimR + WG * ssimG + WB * ssimB;
}

void SSIM::debugPrint() {
    cout << "SSIM Debug Info:" << endl;
    cout << "C1: " << C1 << ", C2: " << C2 << endl;
    cout << "R channel:" << endl;
    for (const auto& row : R) {
        for (const auto& val : row) {
            cout << static_cast<int>(val) << " ";
        }
        cout << endl;
    }
    cout << "G channel:" << endl;
    for (const auto& row : G) {
        for (const auto& val : row) {
            cout << static_cast<int>(val) << " ";
        }
        cout << endl;
    }
    cout << "B channel:" << endl;
    for (const auto& row : B) {
        for (const auto& val : row) {
            cout << static_cast<int>(val) << " ";
        }
        cout << endl;
    }
}