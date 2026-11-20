#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include"Image_file_manager.h"
#include<iostream>

//IMAGE LOADING

Image* IO::imageread(char* path){
        unsigned char* pixels;
        if (path == nullptr){
            cout<< "Failed to load image"<<endl;
            return nullptr; }
        pixels= stbi_load(path, &w, &h, &ch, 3);
        if (pixels == nullptr){
            cout<< "Failed to load image"<<endl;
            return nullptr; }
        Image* i= new Image(w,h);
        for(int j=0;j<i->getHeight();j++){
            for(int k=0;k<i->getWidth();k++){
                i->getImageData()[j][k].setR(pixels[3*(j*i->getWidth()+k)+0]);
                i->getImageData()[j][k].setG(pixels[3*(j*i->getWidth()+k)+1]);
                i->getImageData()[j][k].setB(pixels[3*(j*i->getWidth()+k)+2]);
            }
        }
        stbi_image_free(pixels);
        return i;
    }

//IMAGE WRITING    

int IO::imagewrite(char* path,Image* i){
    if(i==nullptr){cout<<"Corrupted Image Reference"<<endl; return 0;}
    if(path==nullptr){cout<<"Invalid Path"<<endl; return 0;}
    int mem=i->getHeight()*i->getWidth()*3;
    unsigned char* pixels=new unsigned char[mem];
        for(int j=0;j<i->getHeight();j++){
            for(int k=0;k<i->getWidth();k++){
            pixels[3*(j*i->getWidth()+k)+0]=(i->getImageData()[j][k].getR());
            pixels[3*(j*i->getWidth()+k)+1]=(i->getImageData()[j][k].getG());
            pixels[3*(j*i->getWidth()+k)+2]=(i->getImageData()[j][k].getB());
        }
    }
    int x=stbi_write_png(path, i->getWidth(), i->getHeight(), 3, pixels, i->getWidth() * 3);
    delete[] pixels;
    return x;
}