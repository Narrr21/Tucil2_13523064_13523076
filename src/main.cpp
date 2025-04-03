#include "cli.hpp"
#include "blok.hpp"
#include "ImageProcess.hpp"
int main(int argc, char *argv[])
{
    cli* handler = new cli();

    ImageProcess image(handler->getImagePath());

    vector<vector<rgb>> rgbMatrix = image.getRGBMatrix();

    // for (size_t i = 0; i < rgbMatrix.size(); i++) {
    //     for (size_t j = 0; j < rgbMatrix[i].size(); j++) {
    //         cout << "(" << rgbMatrix[i][j].getRed() << ", "
    //              << rgbMatrix[i][j].getGreen() << ", "
    //              << rgbMatrix[i][j].getBlue() << ") ";
    //     }
    //     cout << endl; 
    // }


    delete handler;

    return 0;

}