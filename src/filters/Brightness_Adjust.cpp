#include "Brightness_Adjust.h"
#include "Image.h"
#include <iostream>
using namespace std;

Brightness_Adjust::Brightness_Adjust() : level(0) {
}

Brightness_Adjust::~Brightness_Adjust() {
}

int Brightness_Adjust::getLevel() {
    return level;
}

void Brightness_Adjust::setLevel(int l) {
    level = Pixel::clamp(l, -255, 255);
}

void Brightness_Adjust::applyFilter() {
    if (image == nullptr) return;
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            Pixel& p = image->getImageData()[i][j];
            p.setR(Pixel::clamp(p.getR() + level));
            p.setG(Pixel::clamp(p.getG() + level));
            p.setB(Pixel::clamp(p.getB() + level));
        }
    }
}
