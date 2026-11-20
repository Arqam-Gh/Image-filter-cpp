#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "Pixel.h"
using namespace std;

class Image {
private:
    Pixel** imageData;
    int width;
    int height;
    int channels;
public:
    Image();
    Image(int w, int h);
    Image(const Image& other);  // Copy constructor for deep copy
    Image& operator=(const Image& other);
    ~Image();
    int& getWidth();
    int& getHeight();
    int& getchannels();
    Pixel** getImageData();
    
    // Display functions
    void displayASCII();
};

#endif
