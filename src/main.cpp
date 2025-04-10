#include "cli.hpp"
#include "blok.hpp"
#include "MAD.hpp"
#include "ImageProcess.hpp"
#include "gif.h"
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    system("clear");
    cli* handler = new cli();

    auto start = chrono::high_resolution_clock::now();

    ImageProcess image(handler->getImagePath());
    vector<vector<rgb>> rgbMatrix = image.getRGBMatrix();

    error_code ec;
    uintmax_t originalSize = filesystem::file_size(handler->getImagePath(), ec);
    if (ec) {
        cerr << "Error getting input file size: " << ec.message() << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Original image size: " << (originalSize / 1024.0) << " KB" << endl;
    }

    Blok* blok = new Blok(0, 0, rgbMatrix, image.getWidth(), image.getHeight());

    if (blok->divide(handler->getmethod(), handler->getRange(), handler->getMinBlok())) {
        cout << "Total blocks created: " << Blok::getCountBlok() << endl;
        cout << "Max depth reached: " << Blok::getMaxDepth() << endl;

        blok->normalizeRGB();

        GifWriter gifWriter;
        GifBegin(&gifWriter, handler->getGifPath().c_str(), image.getWidth(), image.getHeight(), 100);

        for (int level = 0; level <= Blok::getMaxDepth(); ++level) {
            vector<vector<rgb>> frameMatrix(image.getHeight(), vector<rgb>(image.getWidth()));
            blok->reconstructGif(frameMatrix, level);

            uint8_t* buffer = new uint8_t[image.getWidth() * image.getHeight() * 4];
            int idx = 0;
            for (int y = 0; y < image.getHeight(); ++y) {
                for (int x = 0; x < image.getWidth(); ++x) {
                    buffer[idx++] = frameMatrix[y][x].getRed();
                    buffer[idx++] = frameMatrix[y][x].getGreen();
                    buffer[idx++] = frameMatrix[y][x].getBlue();
                    buffer[idx++] = 255;
                }
            }

            GifWriteFrame(&gifWriter, buffer, image.getWidth(), image.getHeight(), 100);
            delete[] buffer;
        }

        GifEnd(&gifWriter);

        vector<vector<rgb>> outputMatrix(image.getHeight(), vector<rgb>(image.getWidth()));
        blok->reconstructMatrix(outputMatrix);

        ImageProcess outputImage;
        outputImage.saveImage(handler->getOutputPath(), outputMatrix);

        uintmax_t resultSize = filesystem::file_size(handler->getOutputPath(), ec);
        if (ec) {
            cerr << "Error getting output file size: " << ec.message() << endl;
        } else {
            cout << "Result image size: " << (resultSize / 1024.0) << " KB" << endl;
        }

        cout << "Gif saved successfully: " << handler->getGifPath() << endl;

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Processing time: " << duration.count() << " ms" << endl;
    }

    delete handler;
    delete blok;

    return 0;
}
