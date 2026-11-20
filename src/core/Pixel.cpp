#include "Pixel.h"
#include <iostream>
using namespace std;

//Constructors & Destructors

Pixel::Pixel() : R(0), G(0), B(0) {
}

Pixel::Pixel(int r, int g, int b) : R(clamp(r)), G(clamp(g)), B(clamp(b)) {
}

Pixel::~Pixel() {
}

//Getters & Setters

int Pixel::getR() {
    return R;
}

void Pixel::setR(int r) {
    R = clamp(r);
}

int Pixel::getG() {
    return G;
}

void Pixel::setG(int g) {
    G = clamp(g);
}

int Pixel::getB() {
    return B;
}

void Pixel::setB(int b) {
    B = clamp(b);
}

int Pixel::clamp(int value, int minVal, int maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

Pixel Pixel::operator+(const Pixel& other) const {
    int newR = clamp(R + other.R);
    int newG = clamp(G + other.G);
    int newB = clamp(B + other.B);
    return Pixel(newR, newG, newB);
}

ostream& operator<<(ostream& os, const Pixel& p) {
    int brightness = (p.R + p.G + p.B) / 3;
    
    char asciiChar;
    if (brightness < 32) asciiChar = ' ';
    else if (brightness < 64) asciiChar = '.';
    else if (brightness < 96) asciiChar = ':';
    else if (brightness < 128) asciiChar = '-';
    else if (brightness < 160) asciiChar = '=';
    else if (brightness < 192) asciiChar = '+';
    else if (brightness < 224) asciiChar = '*';
    else if (brightness < 240) asciiChar = '#';
    else asciiChar = '@';
    
    os << asciiChar;
    return os;
}
