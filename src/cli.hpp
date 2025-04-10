// cli.hpp

#ifndef CLI_HPP
#define CLI_HPP
#include <iostream>
#include <string>
using namespace std;

class cli
{
private:
    string imagePath;
    string outputPath;
    string gifPath;
    int method;
    int range;
    int minBlok;
public:
    cli();
    ~cli();
    void setImagePath(string path);
    void setOutputPath(string path);
    void setMethod(int method);
    void setRange(int range);
    void setMinBlok(int minBlok);
    string getImagePath();
    string getGifPath();
    string getOutputPath();
    int getmethod();
    int getRange();
    int getMinBlok();
    void debugInfo();
    bool checkMethod();
    bool checkRange();
    bool checkMinBlok();
};

#endif
// cli.hpp