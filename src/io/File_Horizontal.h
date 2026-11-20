#ifndef FILE_HORIZONTAL_H
#define FILE_HORIZONTAL_H

#include "File.h"
using namespace std;

class File_Horizontal : public File {
private:
    string orientation;

public:
    File_Horizontal();
    ~File_Horizontal();
    
    string getOrientation();
    void setOrientation(string o);
};

#endif
