#include "cli.hpp"
#include "blok.hpp"
#include "MAD.hpp"
#include "ImageProcess.hpp"
int main(int argc, char *argv[])
{
    cli* handler = new cli();

    ImageProcess image(handler->getImagePath());

    vector<vector<rgb>> rgbMatrix = image.getRGBMatrix();

    Blok* blok = new Blok(0, 0, rgbMatrix, image.getWidth(), image.getHeight());

    if (blok->divide(handler->getmethod(), handler->getRange(), handler->getMinBlok())) {
        cout << "Block divided successfully." << endl;
        cout << "Total blocks created: " << Blok::getCountBlok() << endl;
        cout << "Max depth reached: " << Blok::getMaxDepth() << endl;
        cout << "Block details:" << endl;
        blok->printBlok(0);
        blok->normalizeRGB();
        vector<vector<rgb>> outputMatrix(image.getHeight(), vector<rgb>(image.getWidth()));
        blok->reconstructMatrix(outputMatrix);

        ImageProcess outputImage;
        outputImage.saveImage(handler->getOutputPath(), outputMatrix);

        cout << "Block details printed successfully." << endl;
    } else {
        cout << "Block is homogeneous or too small to divide." << endl;
    }
    delete handler;

    return 0;

}