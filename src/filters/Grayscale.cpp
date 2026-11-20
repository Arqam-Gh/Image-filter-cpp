#include "Grayscale.h"
#include "Image.h"
#include <iostream>
using namespace std;

Grayscale::Grayscale() : enabled(false) {
}

Grayscale::~Grayscale() {
}

bool Grayscale::isEnabled() {
    return enabled;
}

void Grayscale::setEnabled(bool e) {
    enabled = e;
}

void Grayscale::applyFilter() {
    if (image == nullptr) return;
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            Pixel& p = image->getImageData()[i][j];
            int g = (int)(p.getR() * 0.299 + p.getG() * 0.587 + p.getB() * 0.114);
            g = Pixel::clamp(g);
            p.setR(g);
            p.setG(g);
            p.setB(g);
        }
    }
}
