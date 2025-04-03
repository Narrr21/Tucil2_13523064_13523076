#include "cli.hpp"
#include "blok.hpp"
#include "ImageProcess.hpp"
int main(int argc, char *argv[])
{
    cli* handler = new cli();

    ImageProcess image(handler->getImagePath());

    vector<vector<rgb>> rgbMatrix = image.getRGBMatrix();

    Blok* blok = new Blok(0, 0, rgbMatrix, image.getWidth(), image.getHeight());

    if (blok->divide(handler->getmethod(), handler->getRange(), handler->getMinBlok())) {
        cout << "Block divided successfully." << endl;
    } else {
        cout << "Block is homogeneous or too small to divide." << endl;
    }
    delete handler;

    return 0;

}