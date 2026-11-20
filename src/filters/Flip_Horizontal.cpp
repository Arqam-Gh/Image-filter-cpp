#include "Flip_Horizontal.h"
#include "Image.h"
#include <iostream>
using namespace std;

Flip_Horizontal::Flip_Horizontal() {
}

Flip_Horizontal::~Flip_Horizontal() {
}

void Flip_Horizontal::applyFilter() {
    if (image == nullptr) return;
    int w = image->getWidth();
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < w / 2; j++) {
            Pixel temp = image->getImageData()[i][j];
            image->getImageData()[i][j] = image->getImageData()[i][w - 1 - j];
            image->getImageData()[i][w - 1 - j] = temp;
        }
    }
}
