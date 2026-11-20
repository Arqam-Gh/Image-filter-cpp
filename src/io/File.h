#ifndef FILE_H
#define FILE_H

#include <string>
using namespace std;

class File {
protected:
    string width;
    string height;
    string path;
    string format;

public:
    File();
    ~File();
    
    string getWidth();
    void setWidth(string w);
    string getHeight();
    void setHeight(string h);
    string getPath();
    void setPath(string p);
    string getFormat();
    void setFormat(string f);
};

#endif
