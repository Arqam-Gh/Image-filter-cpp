#include "Blue_Blur.h"
#include "Image.h"
#include <iostream>
using namespace std;

Blue_Blur::Blue_Blur() : intensity(0) {
}

Blue_Blur::~Blue_Blur() {
}

int Blue_Blur::getIntensity() {
    return intensity;
}

void Blue_Blur::setIntensity(int i) {
    intensity = i < 0 ? 0 : i;
}

void Blue_Blur::applyFilter() {
    if (image == nullptr) return;
    int w = image->getWidth();
    int h = image->getHeight();
    Pixel** data = image->getImageData();

    int* blurred = new int[w * h];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int sum = 0;
            int count = 0;
            for (int di = -intensity; di <= intensity; di++) {
                for (int dj = -intensity; dj <= intensity; dj++) {
                    int y = Pixel::clamp(i + di, 0, h - 1);
                    int x = Pixel::clamp(j + dj, 0, w - 1);
                    sum += data[y][x].getB();
                    count++;
                }
            }
            blurred[i * w + j] = sum / count;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            data[i][j].setB(Pixel::clamp(blurred[i * w + j]));
        }
    }
    delete[] blurred;
}
