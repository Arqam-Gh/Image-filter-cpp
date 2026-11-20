#include "Image.h"
#include <iostream>
using namespace std;

Image::Image() : imageData(nullptr), width(0), height(0), channels(3) {
}

Image::Image(int w, int h) : width(w < 0 ? 0 : w), height(h < 0 ? 0 : h), channels(3) {
    imageData = new Pixel*[height];
    for (int i = 0; i < height; i++) {
        imageData[i] = new Pixel[width];
    }
}

Image::Image(const Image& other) : width(other.width), height(other.height), channels(other.channels) {
    imageData = new Pixel*[height];
    for (int i = 0; i < height; i++) {
        imageData[i] = new Pixel[width];
        for (int j = 0; j < width; j++) {
            imageData[i][j] = other.imageData[i][j];
        }
    }
}

Image& Image::operator=(const Image& other) {
    if (this == &other) return *this;
    if (imageData != nullptr) {
        for (int i = 0; i < height; i++) {
            delete[] imageData[i];
        }
        delete[] imageData;
    }
    width = other.width;
    height = other.height;
    channels = other.channels;
    imageData = new Pixel*[height];
    for (int i = 0; i < height; i++) {
        imageData[i] = new Pixel[width];
        for (int j = 0; j < width; j++) {
            imageData[i][j] = other.imageData[i][j];
        }
    }
    return *this;
}

Image::~Image() {
    if (imageData != nullptr) {
        for (int i = 0; i < height; i++) {
            delete[] imageData[i];
        }
        delete[] imageData;
    }
}

int& Image::getWidth() {
    return width;
}

int& Image::getchannels() {
    return channels;
}

int& Image::getHeight() {
    return height;
}

Pixel** Image::getImageData() {
    return imageData;
}

void Image::displayASCII() {
    cout << "=== Image Preview (" << width << " x " << height << ") ===" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << imageData[i][j];
        }
        cout << endl;
    }
    cout << "Image size: " << width << " x " << height << " | Total pixels: " << (width * height) << endl;
}
