#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include <iostream>
#include "Filter.h"
using namespace std;

class Grayscale : public Filter {
private:
    bool enabled;

public:
    Grayscale();
    ~Grayscale();
    
    bool isEnabled();
    void setEnabled(bool e);
    void applyFilter() override;
};

#endif
