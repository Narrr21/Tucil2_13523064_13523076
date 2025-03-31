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
    int EMP;
    int range;
    int minBlok;
public:
    cli();
    ~cli();
    void setImagePath(string path);
    void setOutputPath(string path);
    void setEMP(int emp);
    void setRange(int range);
    void setMinBlok(int minBlok);
    string getImagePath();
    string getOutputPath();
    int getEMP();
    int getRange();
    int getMinBlok();
    void debugInfo();
    bool checkEMP();
    bool checkRange();
    bool checkMinBlok();
};

#endif
// cli.hpp