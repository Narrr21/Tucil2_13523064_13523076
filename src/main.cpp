#include "cli.hpp"
#include "blok.hpp"
#include "MAD.hpp"
#include "ImageProcess.hpp"
int main(int argc, char *argv[])
{
    cli* handler = new cli();

    ImageProcess image(handler->getImagePath());

    delete handler;

    return 0;

}