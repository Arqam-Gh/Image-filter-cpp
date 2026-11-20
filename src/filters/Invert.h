#ifndef INVERT_H
#define INVERT_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Invert : public Filter {
private:
    bool enabled;

public:
    Invert();
    ~Invert();
    
    bool isEnabled();
    void setEnabled(bool e);
    void applyFilter() override;
};

#endif
