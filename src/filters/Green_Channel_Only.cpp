#include "Green_Channel_Only.h"
#include "Image.h"
#include <iostream>
using namespace std;

Green_Channel_Only::Green_Channel_Only() : enabled(false) {
}

Green_Channel_Only::~Green_Channel_Only() {
}

bool Green_Channel_Only::isEnabled() {
    return enabled;
}

void Green_Channel_Only::setEnabled(bool e) {
    enabled = e;
}

void Green_Channel_Only::applyFilter() {
    if (image == nullptr) return;
    for (int i = 0; i < image->getHeight(); i++) {
        for (int j = 0; j < image->getWidth(); j++) {
            image->getImageData()[i][j].setR(0);
            image->getImageData()[i][j].setB(0);
        }
    }
}
