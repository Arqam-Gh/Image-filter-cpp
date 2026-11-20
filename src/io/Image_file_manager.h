#ifndef IMAGE_FILE_MANAGER_H
#define IMAGE_FILE_MANAGER_H
#include <iostream>
#include"Image.h"
#include"stb_image.h"
#include"stb_image_write.h"
using namespace std;

class IO{
    int w=0,h=0,ch=0;
    public:
    Image* imageread(char* path);
    int imagewrite(char* path,Image* i);
};

#endif
