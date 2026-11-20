#ifndef BLUE_BLUR_H
#define BLUE_BLUR_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Blue_Blur : public Filter {
private:
    int intensity;

public:
    Blue_Blur();
    ~Blue_Blur();
    
    int getIntensity();
    void setIntensity(int i);
    void applyFilter() override;
};

#endif
