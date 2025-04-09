#include "cli.hpp"
#include "blok.hpp"
#include "MAD.hpp"
#include "ImageProcess.hpp"
#include <chrono>
#include "gif.h"


int main(int argc, char *argv[])
{

    cli* handler = new cli();

    auto start = chrono::high_resolution_clock::now();

    ImageProcess image(handler->getImagePath());

    vector<vector<rgb>> rgbMatrix = image.getRGBMatrix();

    int originalSize = image.getWidth() * image.getHeight() * 3; 
    cout << "Original image size (before compression): " << originalSize << " bytes" << endl;



    Blok* blok = new Blok(0, 0, rgbMatrix, image.getWidth(), image.getHeight());

    if (blok->divide(handler->getmethod(), handler->getRange(), handler->getMinBlok())) {
        int compressedSize = Blok::getCountBlok() * 3;
        cout << "Compressed image size: " << compressedSize << " bytes" << endl;
        cout << "Total blocks created: " << Blok::getCountBlok() << endl;
        cout << "Max depth reached: " << Blok::getMaxDepth() << endl;

        // cout << "Block details:" << endl;
        // blok->printBlok(0);
        blok->normalizeRGB();

        vector<vector<rgb>> outputMatrix(image.getHeight(), vector<rgb>(image.getWidth()));
        blok->reconstructMatrix(outputMatrix);

        ImageProcess outputImage;
        outputImage.saveImage(handler->getOutputPath(), outputMatrix);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start); 

        cout << "Processing time: " << duration.count() << " ms" << endl;
    }
    delete handler;
    delete blok;

    return 0;

}