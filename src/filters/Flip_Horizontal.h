#ifndef FLIP_HORIZONTAL_H
#define FLIP_HORIZONTAL_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Flip_Horizontal : public Filter {
public:
    Flip_Horizontal();
    ~Flip_Horizontal();

    void applyFilter() override;
};

#endif
