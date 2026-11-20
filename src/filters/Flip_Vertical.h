#ifndef FLIP_VERTICAL_H
#define FLIP_VERTICAL_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Flip_Vertical : public Filter {
public:
    Flip_Vertical();
    ~Flip_Vertical();

    void applyFilter() override;
};

#endif
