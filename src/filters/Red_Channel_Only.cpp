#include "Red_Channel_Only.h"
#include "Image.h"
#include <iostream>
using namespace std;

Red_Channel_Only::Red_Channel_Only() : enabled(false) {
}

Red_Channel_Only::~Red_Channel_Only() {
}

bool Red_Channel_Only::isEnabled() {
    return enabled;
}

void Red_Channel_Only::setEnabled(bool e) {
    enabled = e;
}

void Red_Channel_Only::applyFilter() {
    if (image == nullptr) return;
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            image->getImageData()[i][j].setG(0);
            image->getImageData()[i][j].setB(0);
        }
    }
}
