#include "cli.hpp"

cli::cli()
{
    cout << "Welcome !" << endl;
    cout << "Please enter the image path: " << endl;
    cin >> imagePath;
    cout << "Please enter the output path: " << endl;
    cin >> outputPath;
    cout << "Please enter the EMP: " << endl;
    cin >> EMP;
    cout << "Please enter the range: " << endl;
    cin >> range;
    cout << "Please enter the minBlok: " << endl;
    cin >> minBlok;
}

cli::~cli()
{
    cout << "Good Bye !" << endl;
}

void cli::setImagePath(string path)
{
    imagePath = path;
}
void cli::setOutputPath(string path)
{
    outputPath = path;
}
void cli::setEMP(int emp)
{
    EMP = emp;
}
void cli::setRange(int range)
{
    this->range = range;
}
void cli::setMinBlok(int minBlok)
{
    this->minBlok = minBlok;
}
string cli::getImagePath()
{
    return imagePath;
}
string cli::getOutputPath()
{
    return outputPath;
}
int cli::getEMP()
{
    return EMP;
}
int cli::getRange()
{
    return range;
}
int cli::getMinBlok()
{
    return minBlok;
}
void cli::debugInfo()
{
    cout << "Image Path  : " << imagePath << endl;
    cout << "Output Path : " << outputPath << endl;
    cout << "EMP         : " << EMP << endl;
    cout << "Range       : " << range << endl;
    cout << "Min Blok    : " << minBlok << endl;
}

bool cli::checkEMP()
{
    // later
    return true;
}
bool cli::checkRange()
{
    // later
    return true;
}
bool cli::checkMinBlok()
{
    // later
    return true;
}