#include "Flip_Vertical.h"
#include "Image.h"
#include <iostream>
using namespace std;

Flip_Vertical::Flip_Vertical() {
}

Flip_Vertical::~Flip_Vertical() {
}

void Flip_Vertical::applyFilter() {
    if (image == nullptr) return;
    int h = image->getHeight();
    for (int i = 0; i < h / 2; i++) {
        Pixel* temp = image->getImageData()[i];
        image->getImageData()[i] = image->getImageData()[h - 1 - i];
        image->getImageData()[h - 1 - i] = temp;
    }
}
