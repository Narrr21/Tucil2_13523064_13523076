#include "ImageProcess.hpp"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

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

ImageProcess::~ImageProcess() {
    if (imageData) {
        stbi_image_free(imageData);
    }
}