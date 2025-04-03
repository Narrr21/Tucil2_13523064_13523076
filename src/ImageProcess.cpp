#include "ImageProcess.hpp"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"


ImageProcess::ImageProcess() : imageData(nullptr), width(0), height(0), channels(0) {}

ImageProcess::ImageProcess(const string& filename) {
    imageData = stbi_load(filename.c_str(), &width, &height, &channels, 0);
    if (imageData == nullptr) {
        cerr << "Error loading image: " << stbi_failure_reason() << endl;
        exit(1);
    }
}

vector<vector<rgb>> ImageProcess::getRGBMatrix() {
    vector<vector<rgb>> rgbMatrix(height, vector<rgb>(width));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * channels;
            rgbMatrix[y][x] = rgb(imageData[index], imageData[index + 1], imageData[index + 2]);
        }
    }
    return rgbMatrix;
}

void ImageProcess::saveImage(const string& filename, const vector<vector<rgb>>& rgbMatrix) {
    int width = rgbMatrix[0].size();
    int height = rgbMatrix.size();

    vector<unsigned char> imageData(width * height * 3);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            imageData[index] = rgbMatrix[y][x].getRed();
            imageData[index + 1] = rgbMatrix[y][x].getGreen();
            imageData[index + 2] = rgbMatrix[y][x].getBlue();
        }
    }

    if (stbi_write_png(filename.c_str(), width, height, 3, imageData.data(), width * 3)) {
        cout << "Image saved successfully: " << filename << endl;
    } else {
        cerr << "Error saving image: " << stbi_failure_reason() << endl;
    }
}

int ImageProcess::getWidth() const {
    return width;
}

int ImageProcess::getHeight() const {
    return height;
}

ImageProcess::~ImageProcess() {
    if (imageData) {
        stbi_image_free(imageData);
    }
}