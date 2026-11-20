#ifndef FILE_VERTICAL_H
#define FILE_VERTICAL_H

#include "File.h"
using namespace std;

class File_Vertical : public File {
private:
    string orientation;

public:
    File_Vertical();
    ~File_Vertical();
    
    string getOrientation();
    void setOrientation(string o);
};

#endif
