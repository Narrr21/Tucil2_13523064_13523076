#ifndef IMAGEPROCESS_HPP
#define IMAGEPROCESS_HPP
#include <string>
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>
#include "rgb.hpp"
#include <vector>
using namespace std;

class ImageProcess {
    private:
        int width, height, channels;
        unsigned char* imageData;
    public:
        ImageProcess(const string& filename);
        vector<vector<rgb>> getRGBMatrix();
        ~ImageProcess();
        int getWidth() const;
        int getHeight() const;

};
#endif