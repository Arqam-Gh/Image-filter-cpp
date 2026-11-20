#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
using namespace std;

class Pixel {
private:
    int R;
    int G;
    int B;

public:
    Pixel();
    Pixel(int r, int g, int b);
    ~Pixel();
    int getR();
    void setR(int r);
    int getG();
    void setG(int g);
    int getB();
    void setB(int b);
    static int clamp(int value, int minVal = 0, int maxVal = 255);
    Pixel operator+(const Pixel& other) const;
    friend ostream& operator<<(ostream& os, const Pixel& p);
};

#endif
