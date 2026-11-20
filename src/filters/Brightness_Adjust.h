#ifndef BRIGHTNESS_ADJUST_H
#define BRIGHTNESS_ADJUST_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Brightness_Adjust : public Filter {
private:
    int level;

public:
    Brightness_Adjust();
    ~Brightness_Adjust();
    
    int getLevel();
    void setLevel(int l);
    void applyFilter() override;
};

#endif
