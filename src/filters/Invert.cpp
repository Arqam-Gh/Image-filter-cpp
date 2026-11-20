#include "Invert.h"
#include "Image.h"
#include <iostream>
using namespace std;

Invert::Invert() : enabled(false) {
}

Invert::~Invert() {
}

bool Invert::isEnabled() {
    return enabled;
}

void Invert::setEnabled(bool e) {
    enabled = e;
}

void Invert::applyFilter() {
    if (image == nullptr) return;
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            Pixel& p = image->getImageData()[i][j];
            p.setR(255 - p.getR());
            p.setG(255 - p.getG());
            p.setB(255 - p.getB());
        }
    }
}
